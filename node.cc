// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data)  {
	stored_char = data;
	prev_node = nullptr;
	next_node = nullptr;
	return;
}

char Node::GetData() {
	return stored_char;
}

Node* Node::GetPreviousNode() {
	return prev_node;
}

Node* Node::GetNextNode() {
	return next_node;
}

Node* Node::InsertPreviousNode(char data) {
	Node* new_node = new Node(data);
	if (new_node == nullptr) return nullptr;
	if (prev_node == nullptr) {
		prev_node = new_node;
		new_node->next_node = this;
	}
	else {
		Node* temp_prev_node = prev_node;
		temp_prev_node->next_node = new_node;
		new_node->prev_node = temp_prev_node;
		new_node->next_node = this;
		prev_node = new_node;
	}
	return new_node;
}

Node* Node::InsertNextNode(char data) {
	Node* new_node = new Node(data);
	if (new_node == nullptr) return nullptr;
	if (next_node == nullptr) {
		next_node = new_node;
		new_node->prev_node = this;
	}
	else {
		Node* temp_next_node = next_node;
		next_node = new_node;
		new_node->prev_node = this;
		new_node->next_node = temp_next_node;
		temp_next_node->prev_node = new_node;
	}
	return new_node;
}

bool Node::ErasePreviousNode() {
	Node* del_node = prev_node;
	if (del_node == nullptr) return false;
	prev_node = del_node->prev_node;
	if (prev_node != nullptr) {
		prev_node->next_node = this;
	}	
	delete del_node;
	return true;
}

bool Node::EraseNextNode() {
	Node* del_node = next_node;
	if (del_node == nullptr) return false;
	next_node = del_node->next_node;
	if (next_node != nullptr) {
		next_node->prev_node = this;
	}
	delete del_node;
	return true;
}
