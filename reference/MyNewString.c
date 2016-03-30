#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/* This code is illegal */
jstring MyNewString(JNIEnv *env, jchar *chars, jint len) {
  static jclass stringClass;
  jmethodID cid;
  jcharArray elemArr;
  jstring result;
  if(!stringClass) {
      stringClass = (*env)->FindClass(env, "java/lang/String");
      if(!stringClass){
        return 0; /* exception thrown */
      }
  }
  /* It is wrong to use the cached stringClass here' 
   * because it may be invalid. */
  cid = (*env)->GetMethodID(env, stringClass, "<init>", "([C)V");
  if(!cid) {
      return 0; /* exception thrown */
  }
  /* Create a char[] that holds the string characters */
  elemArr = (*env)->NewCharArray(env, len);
  if(!elemArr) {
    return 0; /* exception thrown */
  }
  (*env)->SetCharArrayRegion(env, elemArr, 0, len, chars);
  /* Construct a java.lang.String */
  result = (*env)->NewObject(env, stringClass, cid, elemArr);
  /* Free local references */
  (*env)->DeleteLocalRef(env, elemArr);
  return result;
}
#ifdef __cplusplus
}
#endif
