#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     InstanceMethodCall
 * Method:    nativeMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_InstanceMethodCall_nativeMethod
  (JNIEnv *env, jobject obj){
  jclass cls = (*env)->GetObjectClass(env, obj); 
  jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "()V");
  if(!mid) {
    return; /* method not found */
  }
  printf("In C\n");
  (*env)->CallVoidMethod(env, obj, mid);
}

#ifdef __cplusplus
}
#endif
