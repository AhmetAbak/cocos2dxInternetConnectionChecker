This helper class is mostly created from the codes taken from internet .( mostly stackoverflow.com )
Main aim of this code pieces is to unify the internet check for iOS and Android OS for cocos2d-x.
I didnt try it for other tools. But it may work with small changes.

In iOS folder there 2 classes. Just add them to proj.ios_mac/ios folder.
In Android folder there is 1 class. add it to proj.android-studio/app/src/your/package/name.
And lastly;
In CocosProject folder add InternetStatus file to somewhere in Classes. 
Important note:
you have to change the package names in JNI methods in InternetStatus to your package name.
Currently they are com/sngict/game/connection/Connectivity.
you should have to convert them to your/package/name/Connectivity to make them work.

there are 3 basic static functions usages are simple:

    InternetStatus::hasInternetConnection();
    InternetStatus::isConnectionFast();
    InternetStatus::isConnectionTypeMobile();

code tested in iOS 7+ and Android 4.1.3+. 

happy coding! :)