// 4_26_目录树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//在ZIP归档文件中，保留着所有压缩文件和目录的相对路径和名称。当使用WinZIP等GUI软件打开ZIP归档文件时，可以从这些信息中重建目录的树状结构。请编写程序实现目录的树状结构的重建工作。

//输入格式:
//输入首先给出正整数N（≤10^4），表示ZIP归档文件中的文件和目录的数量。随后N行，每行有如下格式的文件或目录的相对路径和名称（每行不超过260个字符）：
//路径和名称中的字符仅包括英文字母（区分大小写）；
//符号“\”仅作为路径分隔符出现；
//目录以符号“\”结束；
//不存在重复的输入项目；
//整个输入大小不超过2MB。
//输出格式 :
//假设所有的路径都相对于root目录。从root目录开始，在输出时每个目录首先输出自己的名字，然后以字典序输出所有子目录，然后以字典序输出所有文件。注意，在输出时，应根据目录的相对关系使用空格进行缩进，每级目录或文件比上一级多缩进2个空格。

#include <iostream>
#include <string>

struct TNode {
	int space;//记录打印空格数
	int prior;//标记是文件还是目录，文件优先级0，目录优先级1(优先级大的优先)
	char name[261];//文件名
	struct TNode* son, * sib;//孩子、兄弟结点指针
};
int IsChar(char c) {//判断是否是英文字母
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}
int cmp(struct TNode* p, struct TNode* q) {//先按优先级比较优先级，优先级相等再按字典序比较
	if (p->prior > q->prior)
		return 1;
	if (p->prior == q->prior) {
		if (strcmp(p->name, q->name) < 0)
			return 1;
		if (strcmp(p->name, q->name) == 0)
			return -1;
	}
	return 0;
}
void Out(struct TNode* root) {//输出打印
	int i;
	if (root) {
		for (i = 0; i < root->space; i++) {
			printf(" ");
		}
		printf("%s\n", root->name);
		Out(root->son);
		Out(root->sib);
	}

}
struct TNode* NewNode(struct TNode* root, char* name, int prior) {//新结点
	struct TNode* node;
	node = (struct TNode*)malloc(sizeof(struct TNode));
	strcpy(node->name, name);
	node->sib = node->son = NULL;
	node->prior = prior;
	node->space = root->space + 2;
	return node;

}
struct TNode* Add(struct TNode* root, char* name, int prior) {//插入结点 
	struct TNode* p = root;
	struct TNode* node = NewNode(root, name, prior);
	if (p->son == NULL) {
		p->son = node;
		return p->son;
	}
	else {
		if (cmp(node, p->son) == 1) {//前插 
			node->sib = p->son;
			p->son = node;
			return p->son;
		}
		else if (cmp(node, p->son) == -1) {//结点相同，返回结点位置即可 
			return p->son;
		}
		else {//同一层则往兄弟结点找 
			p = p->son;
			while (p->sib) {
				if (cmp(node, p->sib) == 1) {//前插 
					node->sib = p->sib;
					p->sib = node;
					return p->sib;
				}
				else if (cmp(node, p->sib) == -1) {//结点相同，返回结点位置即可 
					return p->sib;
				}
				p = p->sib;
			}
			if (!p->sib) {//找到末尾插入即可 
				p->sib = node;
				return p->sib;
			}
		}
	}

}
int main() {
	struct TNode* root = (struct TNode*)malloc(sizeof(struct TNode));
	root->sib = root->son = NULL;
	root->space = 0;
	root->prior = 1;
	strcpy(root->name, "root");
	char input[261];
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%s", input);
		int j, k = 0, prior = 0;
		char name[261];
		struct TNode* p = root;
		for (j = 0; input[j] != '\0'; j++) {
			if (IsChar(input[j]))
				name[k++] = input[j];
			else if (input[j] == '\\') {
				name[k] = '\0';
				prior = 1;
				p = Add(p, name, prior);
				k = 0;
			}
		}
		if (input[j] == '\0' && IsChar(input[j - 1])) {
			name[k] = '\0';
			prior = 0;
			p = Add(p, name, prior);
		}

	}
	Out(root);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
