#include <jni.h>
#include <string>


jstring com_demon_so_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from dynamic register jni function";
    return env->NewStringUTF(hello.c_str());
}


const JNINativeMethod gMethodArray[] = {
        {
            "stringFromJNI",
            "()Ljava/lang/String;",
             (void*)com_demon_so_MainActivity_stringFromJNI
        }
};


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* /* reserved */)
{

    JNIEnv* env = NULL;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return JNI_FALSE;
    }

    jclass  jClass = env->FindClass("com/demon/so/MainActivity");

    if(env->RegisterNatives(jClass,gMethodArray,sizeof(gMethodArray) / sizeof(gMethodArray[0]))<0){
        return JNI_FALSE;
    };

    return JNI_VERSION_1_4;
}