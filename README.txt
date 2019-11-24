# HuffmanTreeCompression
Use C/C++ to implement a Huffman tree to handle text compression.
This project is just an experiment of my Data Structure and 
Algorithm Analysis lesson. It is developed and maintained by my 
team mates and I.
Any suggestion or idea is welcome.
使用C/C++实现哈弗曼树，用于文本压缩。
这只是我的数据结构与算法课程实验，由我和我的小组成员共同维护。
欢迎大家向我们提出意见和建议！

-----------------------------------------------------------------
程序需求：
1.对文本文件进行压缩，产生一个新的文件储存在原目录下。
2.对压缩后文件进行解压缩，产生一个新的文本文件储存在原目录下。
3.将原文件压缩得尽可能小（注意附加信息的大小）。

-----------------------------------------------------------------
零散的想法：
1.自己写一个HuffmanTree类
2.压缩后文件的应储存文件识别信息（可以是0xDEADBEEF），频数表大小，压缩
后数据大小，频数表，压缩后数据。
3.以UTF-16格式编码，这样可以兼容本地的常用文字类型。
4.注意处理文件I/O异常。

-----------------------------------------------------------------
其它：
希望大家能在这个平台上及时更新自己的进展并积极push队友#(滑稽)
