#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     InstanceFieldAccess
 * Method:    accessField
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_InstanceFieldAccess_accessField
  (JNIEnv * env, jobject obj){
  static jfieldID fid_s; /* store the field ID */
  jstring jstr;
  const char* str;
  /* Get a reference to obj's class */
  jclass cls = (*env)->GetObjectClass(env, obj);
  printf("In C: \n");

  /*Look for the instance field s in cls */
  if(!fid_s){
      fid_s = (*env)->GetFieldID(env, cls, "s", "Ljava/lang/String;");
      if(!fid_s) {
        return; /* failed to find the field ！*/
      }
  }
  /* Read the instance field s */
  jstr = (*env)->GetObjectField(env, obj, fid_s);
  str = (*env)->GetStringUTFChars(env, jstr, NULL);
  if(!str) {
    return; /* out of memory */
  }
  printf("    c.s = \"%s\"\n", str);
  (*env)->ReleaseStringUTFChars(env, jstr, str);
  /* Create a new string and overwrite the instance field */
  jstr = (*env)->NewStringUTF(env, "123");
  if(!jstr) {
    return; /*out of memory */
  } 
  (*env)->SetObjectField(env, obj, fid_s, jstr);
}

#ifdef __cplusplus
}
#endif
