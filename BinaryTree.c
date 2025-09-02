#include "stdio.h"
#include "stdlib.h"
typedef int Element;


typedef struct Node{
  Element data;
  struct Node* right;
  struct Node* left;
}Node;

Node* createNode(Element e)
{
  Node* tmp = (Node*)malloc(sizeof(Node));
  tmp->data = e;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}

Node* insertNode(Node* root, Node* node)
{
  if(root == NULL)
  {
    return node;
  }

  if(node->data < root->data) root->left = insertNode(root->left, node);
  else if(node->data > root->data) root->right = insertNode(root->right, node);

  return root;
}

Node* binarysearch(Node* root, Element e)
{
  if(root == NULL || root->data == e){
    return root;
  }
  if(root->data > e) return binarysearch(root->left, e);
  else if(root-> data < e) return binarysearch(root->right, e);
}

int main(void)
{
  Node* root = NULL;
  Node* foundNode = NULL;

  // 트리 생성
  root = insertNode(root, createNode(30));
  insertNode(root, createNode(15));
  insertNode(root, createNode(45));
  insertNode(root, createNode(10));
  insertNode(root, createNode(20));

  // 탐색
  int searchValue = 20;
  foundNode = binarysearch(root, searchValue);

  if (foundNode != NULL) {
      printf("탐색 성공: %d\n", foundNode->data);
  } else {
      printf("%d 값을 찾지 못했습니다.\n", searchValue);
  }

  searchValue = 100;
  foundNode = binarysearch(root, searchValue);
  
  if (foundNode != NULL) {
      printf("탐색 성공: %d\n", foundNode->data);
  } else {
      printf("%d 값을 찾지 못했습니다.\n", searchValue);
  }
  
  return 0;

}
