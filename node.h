// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

class Node {
	char stored_char = 0;
	Node* prev_node = nullptr;
	Node* next_node = nullptr;
 public:
  explicit Node(char data);
  char GetData();
  Node* InsertPreviousNode(char data);
  Node* InsertNextNode(char data);
  Node* GetPreviousNode();
  Node* GetNextNode();
  bool ErasePreviousNode();
  bool EraseNextNode();
};

#endif  // NODE_H_
