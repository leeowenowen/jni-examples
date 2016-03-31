#include <jni.h>
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     Window
 * Method:    initIDs
 * Signature: ()V
 */
jfieldID FID_Window_handle;
jfieldID FID_Window_length;
jfieldID FID_Window_width;
JNIEXPORT void JNICALL Java_Window_initIDs
  (JNIEnv * env, jclass classWindow){
  FID_Window_handle = (*env)->GetFieldID(env, classWindow, "handle", "J");
  if(!FID_Window_handle){
      return; /* error occured ! */
  }
  FID_Window_length = (*env)->GetFieldID(env, classWindow, "length", "I");
  if(!FID_Window_length){
      return; /* error occured ! */
  }
  FID_Window_width= (*env)->GetFieldID(env, classWindow, "width", "I");
  if(!FID_Window_width){
      return; /* error occured ! */
  }
  
 /* no check necessary; we are about to return anyway */
}

#ifdef __cplusplus
}
#endif
