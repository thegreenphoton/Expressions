#include "expressions.h"
#include <queue>
using namespace std;

struct ExpressionNode {
  int data;
  char op;
  ExpressionNode* left;
  ExpressionNode* right;
};
  

int evaluate(ExpressionNode* root) {
  if (root->left = nullptr && root->right == nullptr) {
    return root->data;
  }
  else {
    int result = 0;
    int evalLeft = evaluate(root->left);
    int evalRight = evaluate(root->right);
    while (true) {
      if (root->op == '+') {
        result = evalLeft + evalRight;
        break;
      }
      else if (root->op == '-') {
        result = evalLeft - evalRight;
        break;
      }
      else if (root->op == '/') {
        result = evalLeft / evalRight;
        break;
      }
      else if (root->op == '*') {
        result = evalLeft * evalRight;
        break;
      }
    }
    return result;
  }
}

std::string preOrder(ExpressionNode* root) {
  if (root == nullptr) {
    return "";
  }
  else {
    std::string ios = "";
    if (root->left == nullptr && root->right == nullptr) {
      ios += to_string(root->data);
    }
    else {
      ios += root->op;
    }
    string left = preOrder(root->left);
    string right = preOrder(root->right);
    if (!left.empty()) {
      ios += " " + left;
    }
    if (!right.empty()) {
      ios += " " + right;
    }
    return ios;
  }
}

std::string postOrder(ExpressionNode* root) {
  if (root == nullptr) {
    return "";
  }
  else { 
    std::string ios = "";
    string left = postOrder(root->left);
    string right = postOrder(root->right);
    if (!left.empty()) {
      ios += left + "";
    } 
    if (!right.empty()) {
      ios += right + "";
    }
    if (root->left == nullptr && root->right == nullptr) {
      ios += to_string(root->data);
    }
    else {
      ios += root->op;
    }
    return ios;
  }
}

std::string inOrder(ExpressionNode* root) {
  if (root == nullptr) {
    return "";
  }
  else {
    std::string ios = "";
    ios += inOrder(root->left);
    if (root->left == nullptr && root->right == nullptr) {
      ios += to_string(root->data);
    }
    else {
      ios += " ";
      ios += root->op;
      ios += " ";
    }
    ios += inOrder(root->right);
    return ios;
  }
}

std::string breadthFirst(ExpressionNode* root) {
  string bfs = "";
  queue<ExpressionNode*> q;
  q.push(root);
  while (!q.empty()) {
    ExpressionNode* temp = q.front();
    if (!temp->left && !temp->right) {
      bfs += to_string(temp->data);
    }
    else {
      bfs += temp->op;
    }
    q.pop();
    if (temp->left != nullptr) {
      q.push(temp->left);
    }
    if (temp->right != nullptr) {
      q.push(temp->right);
    }
    if (!q.empty()) {
      bfs += " ";
    }
  } 
  return bfs;
}

int height(ExpressionNode* root) {
  if (!root) {
    return -1;
  }
  else {
    return 1 + max(height(root->left, height(root->right));
  }
}

void reverse(ExpressionNode* root) {
  if (root == nullptr) {
    return;
  }
  reverse(root->left);
  reverse(root->right);
  ExpressionNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  return;
}
