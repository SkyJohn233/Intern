
// 单链表
// 反转 
//递归
struct node{
	node *next;
	int val;
	node(int v):val(v),next(nullptr){}
};
void reverse1(node *cur,node *&target) {
	if(cur==nullptr) return;
	node *tar=cur->next;
	cur->next=target;
	reverse1(tar,cur);
	return ;
}

// 非递归
void reverse1(node *&head) {
	node *cur=head->next,*father=nullptr;
	while(cur) {
		node *tar1=cur->next,*tar2=cur;
		cur->next=father;
		cur=tar1;
		father=tar2;
	}
	head->next=cur;
}
// 链表冒泡排序
// 删除节点
void del(node *cur,const int &val) { //cur 为 head 节点
	while(cur) {
		if(cur->next&&cur->next->val==val) {
			cur->next=cur->next->next;
			break;
		}
		cur=cur->next;
	}
	return ;
}
// 在当前节点插入数据x
void add(node *cur,const int& val) {
	node *tar = new node(val);
	node *_next= cur->next;
	cur->next=tar;
	tar->next=_next;
}
// 单链表判环
bool iscircle(const node *&head){
	node *fast=head,*slow=head;
	do{
		fast=fast->next;
		if(!fast) return false;
		fast=fast->next;
		if(!fast) return false;
		slow=slow->next;
		if(!slow) return false;
	}
	while(fast!=slow)
	return true;
}
// 成环的第一个节点 在环中某处断开 然后形成两个单链表 然后求其第一个相交的节点
// 单链表相交
bool iscross(const node *&head1,const node *&head2) {
	node *cur1=head1,*cur2=head2;
	while(cur1->next)
		cur1=cur1->next;
	while(cur2->next)
		cur2=cur2->next;
	return cur1==cur2;
}
// 相交的第一个节点 先判是否相交 然后把差值走掉

//删除某个节点 O(1) 时间 
// 将删除的下一个节点复制到该节点 删除下一个节点即可。

// 跳跃链表skiplist 查找 删除 插入期望时间复杂度O(logn)
