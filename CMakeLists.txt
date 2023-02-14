cmake_minimum_required(VERSION 3.24)
project(GM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(bin)
include_directories(obj)

add_executable(GM
        .idea/.gitignore
        .idea/GM.iml
        .idea/modules.xml
        .idea/workspace.xml
        bin/Debug/GM.exe
        obj/Debug/main.o
        buyerinfo.txt
        GM.cbp
        GM.depend
        GM.layout
        main.cpp
        order.txt
        products.txt
        sellerinfo.txt headers/signup.h headers/common.h headers/login.h headers/menu.h headers/buy.h headers/orders.h headers/account.h headers/sell.h headers/admin.h)
