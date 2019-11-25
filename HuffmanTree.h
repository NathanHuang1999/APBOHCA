#pragma once
#include"header_this.h"

//���������ڵ������
template<typename E> 
class HuffmanNode {
public:
	virtual ~HuffmanNode() {}
	virtual int weight() = 0;		//����Ȩ��
	virtual bool isLeaf() = 0;		//���ؽڵ�����
};

template<typename E>		//Ҷ�ڵ��࣬���������ڵ������
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

template<typename E>		//�ڲ��ڵ��࣬���������ڵ������
class intlNode :public HuffmanNode<E> {
private:
	HuffmanNode<E>* lc;			//������ָ��
	HuffmanNode<E>* rc;			//������ָ��
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

//����������
template<typename E>
class HuffmanTree {
private:
	HuffmanNode<E>* root;		//ȫ���ĸ��ڵ�
public:
	HuffmanTree(E& val, int freq) {			//Ҷ�ӹ��캯��
		root = new LeafNode<E>(val, freq);
	}
	//�ڲ��ڵ㹹�캯��
	HuffmanTree(HuffmanTree<E>* l, HuffmanTree<E>* r) {
		root = new intlNode<E>(l->root(), r->root());
	}
	~HuffmanTree(){}
	HuffmanNode<E>* root() { return root; }
	int weight() { return root->weight(); }
};