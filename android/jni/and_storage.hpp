/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_guidewithme_cpp_Storage */

#ifndef _Included_com_guidewithme_cpp_Storage
#define _Included_com_guidewithme_cpp_Storage
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_guidewithme_cpp_Storage
 * Method:    nativeCreate
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_guidewithme_cpp_Storage_nativeInit
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_guidewithme_cpp_Storage
 * Method:    getArticleInfoByUrl
 * Signature: (Ljava/lang/String;)Lcom/example/travelguide/article/ArticleInfo;
 */
JNIEXPORT jobject JNICALL Java_com_guidewithme_cpp_Storage_getArticleInfoByUrl
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_guidewithme_cpp_Storage
 * Method:    query
 * Signature: (Ljava/lang/String;ZDD)V
 */
JNIEXPORT void JNICALL Java_com_guidewithme_cpp_Storage_query
  (JNIEnv *, jobject, jstring, jboolean, jdouble, jdouble);

/*
 * Class:     com_guidewithme_cpp_Storage
 * Method:    getResultSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_guidewithme_cpp_Storage_getResultSize
  (JNIEnv *, jobject);

/*
 * Class:     com_guidewithme_cpp_Storage
 * Method:    getArticleInfoByIndex
 * Signature: (I)Lcom/example/travelguide/article/ArticleInfo;
 */
JNIEXPORT jobject JNICALL Java_com_guidewithme_cpp_Storage_getArticleInfoByIndex
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_guidewithme_cpp_Storage
 * Method:    isValidLatLon
 * Signature: (DD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_guidewithme_cpp_Storage_isValidLatLon
  (JNIEnv *, jclass, jdouble, jdouble);

#ifdef __cplusplus
}
#endif
#endif
