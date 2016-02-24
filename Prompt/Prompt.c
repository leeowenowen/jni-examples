#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Prompt
 * Method:    getLine
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_Prompt_getLine
  (JNIEnv * env, jobject obj, jstring prompt){
  char buf[128];
  const jbyte* str = (*env)->GetStringUTFChars(env, prompt, NULL);
  if(!str){
    return NULL;
  }
  printf("%s", str);
  (*env)->ReleaseStringUTFChars(env,prompt,str);
  /*We assume here that the user does not type more than 127 characters */
  scanf("%s", buf);
  return (*env)->NewStringUTF(env, buf);
}

JNIEXPORT jstring JNICALL Java_Prompt_getLine2
  (JNIEnv * env, jobject obj, jstring prompt){
  /* assume the prompt string and user input has less than 128 characters */
  char outbuf[128], inbuf[128];
  int len = (*env)->GetStringLength(env, prompt);
  (*env)->GetStringUTFRegin(env, prompt, 0, len, outbuf);
  printf("%s", output);
  scanf("%s", inbuf);
  return (*env)->NewStringUTF(env, inbuf);
}

void GetReleaseStringCriticalExample(JNIEnv* env, jstring jstr1, jstring jstr2){
  jchar* s1 = (*env)->GetStringCritical(env, jstr1);
  if(!s1) {
      /* error handling */
  }
  jchar* s2 = (*env)->GetStringCritical(env, jstr2);
  if(!s2) {
      (*env)->ReleaseStringCritical(env, jstr1, s1);
      /* error handling */
  }
  /* use s1 and s2 */
  (*env)->ReleaseStringCritical(env, jstr1, s1);
  (*env)->ReleaseStringCritical(env, jstr2, s2);
}


#ifdef __cplusplus
}
#endif
