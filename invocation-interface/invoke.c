#define _JNI_IMPLEMENTATION_
#include <jni.h>
#define PATH_SEPERATOR ";" /* define it to be ':' on Solaris */
#define USER_CLASSPATH "." /* where Prog.class is */
#ifdef __cplusplus
extern "C" {
#endif
void destroy(JNIEnv* env, JavaVM *jvm){
  if ((*env)->ExceptionOccurred(env)) {
    (*env)->ExceptionDescribe(env);
  }
  (*jvm)->DestroyJavaVM(jvm);
}
int main() {
  JNIEnv *env;
  JavaVM *jvm;
  jint res;
  jclass cls;
  jmethodID mid;
  jstring jstr;
  jclass stringClass;
  jobjectArray args;
#ifdef JNI_VERSION_1_2
  JavaVMInitArgs vm_args;
  JavaVMOption options[1];
  options[0].optionString = "-Djava.class.path=" USER_CLASSPATH;
  vm_args.version = 0x00010002;
  vm_args.options = options;
  vm_args.nOptions = 1;
  vm_args.ignoreUnrecognized = JNI_TRUE;
  /* Create the Java VM */
  res = JNI_CreateJavaVM(&jvm, (void**)&env, (void*)&vm_args);
#else 
  JDK1_1InitArgs vm_args;
  char classpath[1024];
  vm_args.version = 0x00010001;
  JNI_GetDefaultJavaVMInitArgs(&vm_args);
  /* Append USER_CLASSPATH to the default system class path */
  sprintf(classpath, "%s%c%s", vm_args.classpath, PATH_SEPERATOR, USER_CLASSPATH);
  vm_args.classpath = classpath;
  /* Create the Java VM */
  res = JNI_CreateJavaVM(&jvm, &env, &vm_args);
#endif /* JNI_VERSION_1_2 */
  if (res < 0){
    fprintf(stderr, "Can't create Java VM\n");
    return 1;
  }
  cls = (*env)->FindClass(env, "Prog");
  if(!cls){
    destroy(env, jvm);
    return 1;
  }

  mid = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");
  if(!mid){
    destroy(env, jvm);
    return 1;
  }

  jstr = (*env)->NewStringUTF(env, " From C!");
  if(!jstr){
    destroy(env, jvm);
    return 1;
  }
  stringClass = (*env)->FindClass(env, "java/lang/String");
  args = (*env)->NewObjectArray(env, 1, stringClass, jstr);
  if(!args){
    destroy(env, jvm);
    return 1;
  }

  (*env)->CallStaticVoidMethod(env, cls, mid, args);

  destroy(env, jvm);
  return 0;
}

#ifdef __cplusplus
}
#endif
