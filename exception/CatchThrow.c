#include <jni.h>
#ifdef __cplusplus
extern "C" {
#endif
void JNU_ThrowByName(JNIEnv *env, const char* name, const char* msg){
  jclass cls = (*env)->FindClass(env, name);
  /*if cls is NULL, an exception has already been thrown */
  if(cls){
    (*env)->ThrowNew(env, cls, msg);
  }
  /* free the local ref */
  (*env)->DeleteLocalRef(env, cls);
}
/*
 * Class:     CatchThrow
 * Method:    doit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_CatchThrow_doit
  (JNIEnv * env, jobject obj){
  jthrowable exc;
  jclass cls = (*env)->GetObjectClass(env, obj);
  jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "()V");
  if(!mid){
    return;
  }
  (*env)->CallVoidMethod(env, obj, mid);
  exc = (*env)->ExceptionOccurred(env);
  if(exc){
      /*
       * We don't do much with the exception, except that we print a debug message for it,
       * clear it, and throw a new exception.
       */
      jclass newExcCls;
      (*env)->ExceptionDescribe(env);
      (*env)->ExceptionClear(env);
      JNU_ThrowByName(env, "java/lang/IllegalArgumentException", "Throw from C code");
      //newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
      //if(!newExcCls){
      //  /*Unable to find the exception class, give up. */
      //  return;
      //}
      //(*env)->ThrowNew(env, newExcCls, "thrown from C code");
  }
}
jvalue JNU_CallMethodByName(JNIEnv *env, jboolean * hasException, jobject obj, const char * name, const char*descriptor, ...){
    va_list args;
    jclass clazz;
    jmethodID mid;
    jvalue result;
    if((*env)->EnsureLocalCapacity(env, 2) == JNI_OK) {
      clazz = (*env)->GetObjectClass(env, obj);
      mid = (*env)->GetMethodID(env, clazz, name, descriptor);
      if(mid){
        const char *p = descriptor;
        /*skip over argument types to find out the return type */
        while(*p != ')') p++;
        /* skip ')' */
        p ++;
        va_start(args, descriptor);
        switch(*p){
          case 'V':
              (*env)->CallVoidMethod(env, obj, mid, args);
              break;
          case '[':
          case 'L':
              result.l = (*env)->CallObjectMethodV(env, obj, mid, args);
              break;
          case 'Z':
              result.z = (*env)->CallBooleanMethodV(env, obj, mid, args);
              break;
          case 'B':
              result.b = (*env)->CallByteMethodV(env, obj, mid, args);
              break;
          case 'C':
              result.c = (*env)->CallCharMethodV(env, obj, mid, args);
              break;
          case 'S':
              result.s = (*env)->CallShortMethodV(env, obj, mid, args);
              break;
          case 'I':
              result.i = (*env)->CallIntMethodV(env, obj, mid, args);
              break;
          case 'J':
              result.j = (*env)->CallLongMethodV(env, obj, mid, args);
              break;
          case 'F':
              result.f = (*env)->CallFloatMethodV(env, obj, mid, args);
              break;
          case 'D':
              result.d = (*env)->CallDoubleMethodV(env, obj, mid, args);
              break;
          default:
              (*env)->FatalError(env, "illegal descriptor");
        }
        va_end(args);
      }
      (*env)->DeleteLocalRef(env, clazz);
    }
    if(hasException){
      *hasException = (*env)->ExceptionCheck(env);
    }
    return result;
}


#ifdef __cplusplus
}
#endif
