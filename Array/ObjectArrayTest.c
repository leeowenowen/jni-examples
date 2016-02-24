#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     ObjectArrayTest
 * Method:    initInt2DArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_ObjectArrayTest_initInt2DArray
  (JNIEnv * env, jclass cls, jint size) {
  jobjectArray result;
  int i;
  jclass intArrCls = (*env)->FindClass(env, "[I");
  if(!intArrCls) {
    return NULL; /* exception thrown */
  }
  result = (*env)->NewObjectArray(env, size, intArrCls, NULL);
  if(!result) {
    return NULL; /* out of memory error thrown */
  }
  for (i = 0; i < size; ++i) {
    jint tmp[256]; /* make sure it is large enough! */
    int j;
    jintArray iarr = (*env)->NewIntArray(env, size);
    if(!iarr) {
      return NULL;
    }
    for (j = 0; j < size; j ++) {
      tmp[j] = i + j;
    }
    (*env)->SetIntArrayRegion(env, iarr, 0, size, tmp);
    (*env)->SetObjectArrayElement(env, result, i, iarr);
    (*env)->DeleteLocalRef(env, iarr);
  }
  return result;
}

#ifdef __cplusplus
}
#endif

