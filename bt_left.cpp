#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct Treenode
{
	Treenode *right,*left;
	int val;
	Treenode (int v):val(v),right(nullptr),left(nullptr) {}
};

void build(Treenode* cur) {
	cout<<cur<<' '<<cur->val<<endl;
	int l,r;cin>>l>>r;
	if(l>=0)
		cur->left=new Treenode(l);
	if(r>=0) 
		cur->right=new Treenode(r);
	if(cur->left) build(cur->left);
	if(cur->right) build(cur->right);
}
int h=-1;
void work(Treenode *cur,int hh) {
	if(hh>h) {
		cout<<cur->val<<endl;
		h=hh;
	}
	if(cur->left) work(cur->left,hh+1);
	if(cur->right) work(cur->right,hh+1);
} 
int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	Treenode *root=nullptr;
	int rt;cin>>rt;
	root = new Treenode(rt);
	build(root);
	work(root,0);
	return 0;
}