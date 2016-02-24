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
  jint buf[10];
  jint i, sum = 0;
  (*env)->GetIntArrayRegion(env, arr, 0, 10, buf);
  for (int i =0; i < 10; i ++){
    sum += buf[i];
  }
  return sum;
}

#ifdef __cplusplus
}
#endif

