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



jmethodID MID_InstanceMethodCall_callback;
JNIEXPORT void JNICALL Java_InstanceMethodCall_nativeMethod2
  (JNIEnv *env, jobject obj){
  printf("In C\n");
  (*env)->CallVoidMethod(env, obj, MID_InstanceMethodCall_callback);
}
/*
 * Class:     InstanceMethodCall
 * Method:    initIDs
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_InstanceMethodCall_initIDs
  (JNIEnv * env , jclass cls ){
  MID_InstanceMethodCall_callback = (*env)->GetMethodID(env, cls, "callback", "()V");
}
#ifdef __cplusplus
}
#endif
