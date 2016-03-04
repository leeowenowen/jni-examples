#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     StaticMethodCall
 * Method:    nativeMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_StaticMethodCall_nativeMethod
  (JNIEnv * env, jobject obj){
  jclass cls = (*env)->GetObjectClass(env, obj);
  jmethodID mid = (*env)->GetStaticMethodID(env, cls, "callback", "()V"); 
  if(!mid) {
    return; /* method not found */
  }
  printf("In C\n");
  (*env)->CallStaticVoidMethod(env, cls, mid);
}

#ifdef __cplusplus
}
#endif
