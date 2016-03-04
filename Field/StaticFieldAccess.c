#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     StaticFieldAccess
 * Method:    accessField
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_StaticFieldAccess_accessField
  (JNIEnv *env, jobject obj) {
  jfieldID fid; /* store the field ID */
  jint si;
  /* Get a reference to obj's class */
  jclass cls = (*env)->GetObjectClass(env, obj);
  printf("In C:\n");
  /* Look for the static field si in cls */
  fid = (*env)->GetStaticFieldID(env, cls, "si", "I");
  if(!fid) {
    return; /* field not found */
  }
  /* Access the static field si */
  si = (*env)->GetStaticIntField(env, cls, fid);
  printf("  StaticFieldAccess.si = %d\n", si);
  (*env)->SetStaticIntField(env, cls, fid, 200);
}

#ifdef __cplusplus
}
#endif
