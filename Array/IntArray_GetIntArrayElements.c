#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     IntArray
 * Method:    sumArray
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_IntArray_sumArray
  (JNIEnv * env, jobject obj, jintArray arr) {
  jint i, sum = 0;
  jint* carr = (*env)->GetIntArrayElements(env, arr, NULL);
  if(!carr) {
    return 0; /* exception occurred */
  }
  for (int i =0; i < 10; i ++){
    sum += carr[i];
  }
  (*env)->ReleaseIntArrayElements(env, arr, carr, 0);
  return sum;
}

#ifdef __cplusplus
}
#endif
