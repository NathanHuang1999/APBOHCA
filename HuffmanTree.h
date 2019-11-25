#pragma once
#include"header_this.h"

//哈弗曼树节点抽象类
template<typename E> 
class HuffmanNode {
public:
	virtual ~HuffmanNode() {}
	virtual int weight() = 0;		//返回权重
	virtual bool isLeaf() = 0;		//返回节点类型
};

template<typename E>		//叶节点类，哈弗曼树节点的子类
class LeafNode :public HuffmanNode<E> {
private:
	E item;
	int weight;
public:
	LeafNode(const E& val, int freq) {
		item = val; 
		weight = freq;
	}
	int weight() { return weight; }
	E val() { return item; }
	bool isLeaf() { return true; }
};

template<typename E>		//内部节点类，哈弗曼树节点的子类
class intlNode :public HuffmanNode<E> {
private:
	HuffmanNode<E>* lc;			//左子树指针
	HuffmanNode<E>* rc;			//右子树指针
	int weight;
public:
	IntlNode(HuffmanNode<E>* l, HuffmanNode<E>* r){
		weight = l->weight() + r->weight();
		lc = l;
		rc = r;
	}
	int weight() { return weight; }
	bool isLeaf() { return false; }
	HuffmanNode<E>* left() const { return lc; }
	void setLeft(HuffmanNode<E>* l) {
		lc = l;
	}
	HuffmanNode<E>* right() const { return rc; }
	void setRight(HuffmanNode<E>* r) {
		rc = r;
	}
};

//哈弗曼树类
template<typename E>
class HuffmanTree {
private:
	HuffmanNode<E>* root;		//全树的根节点
public:
	HuffmanTree(E& val, int freq) {			//叶子构造函数
		root = new LeafNode<E>(val, freq);
	}
	//内部节点构造函数
	HuffmanTree(HuffmanTree<E>* l, HuffmanTree<E>* r) {
		root = new intlNode<E>(l->root(), r->root());
	}
	~HuffmanTree(){}
	HuffmanNode<E>* root() { return root; }
	int weight() { return root->weight(); }
};