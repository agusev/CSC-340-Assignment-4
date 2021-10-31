// CSC340
// Assignment 4
// Copyright 2021 - Aleksandr Gusev
// Email: agusev@sfsu.edu

#include <iostream>

using namespace std;

struct Node
{
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
};

void print(Node *list);

/// <summary>
/// This is where you will implement your solution to the problem:
///
/// Given two linked lists that represent numbers starting with the most significat digit,
/// add the two numbers together and return a list that represents the sum of the two numbers.
///
/// You may assume the numbers are non negative and have no leading zeros.
///
/// Example 1:
/// 321 + 432 = 753
///
///   3 -> 2 -> 1 -> null
/// + 4 -> 3 -> 2 -> null
/// = 7 -> 5 -> 3 -> null
///
/// Example 2:
/// 999 + 99 = 1098
///
///   9 -> 9 -> 9 -> null
/// + 9 -> 9 -> null
/// = 1 -> 0 -> 9 -> 8 -> null
///
/// </summary>
/// <param name="first">A list that represents the first number</param>
/// <param name="second">A list that represents the second number</param>
/// <returns>A list that represents the sum of first and second</returns>

// reverses a list
Node *reverseList(Node *head)
{
  Node *curr = head;
  Node *prev = NULL;
  Node *node;
  while (curr != NULL)
  {
    node = curr->next;
    curr->next = prev;
    prev = curr;
    curr = node;
  }

  return prev;
}

// A list that represents the sum of first and second
Node *addTwoNumbers(Node *first, Node *second)
{
  cout << endl
       << "1st list:\t";
  print(first);
  cout << "2nd list:\t";
  print(second);

  // initial lists reversed
  Node *f = reverseList(first);
  Node *s = reverseList(second);

  // return lists
  Node *third = new Node(0);
  Node *forth = third;

  // sum
  int sumFull = 0;
  // sum / 10
  int sumWhole = 0;
  // sum % 10
  int sumRemained = 0;

  while (f != NULL || s != NULL)
  {
    sumFull = sumWhole;

    // sums data from current nodes if exist
    if (f != NULL)
    {
      sumFull += f->val;
      f = f->next;
    }
    if (s != NULL)
    {
      sumFull += s->val;
      s = s->next;
    } // end if

    // sum to add
    sumRemained = sumFull % 10;
    // sum to the next node
    sumWhole = sumFull / 10;

    forth->val = sumRemained;
    Node *tmp1 = new Node(0);
    forth->next = tmp1;
    forth = forth->next;
  }

  // adds 1 to the last node if sum >= 10
  if (sumWhole == 1)
  {
    forth->val = sumWhole;
    third = reverseList(third);
  }
  else
  {
    Node *tmp2 = third;
    while (tmp2->next != forth)
    {
      tmp2 = tmp2->next;
    }
    tmp2->next = NULL;

    third = reverseList(third);
  }

  cout << "Result: \t";
  print(third);
  cout << endl;

  return third;
}

// output a list to console
void print(Node *list)
{
  while (list != nullptr)
  {
    cout << list->val;
    cout << " -> ";

    if (list->next == NULL)
    {
      cout << "null" << endl;
      break;
    }
    list = list->next;
  }
}

void test(Node *res, Node *key, int testNumber)
{

  while (key != nullptr)
  {
    if (res == nullptr || key->val != res->val)
    {
      cout << "Test " << testNumber << " Failed\n";
      return;
    }
    key = key->next;
    res = res->next;
  }

  cout
      << "------------------------------- END test #" << testNumber << " -------------------------------" << endl;
  cout << "Test " << testNumber << " Passed\n";
}

void test1()
{
  // first number
  Node *first2 = new Node(1);
  Node *first1 = new Node(2, first2);
  Node *first0 = new Node(3, first1);

  // second number
  Node *sec2 = new Node(2);
  Node *sec1 = new Node(3, sec2);
  Node *sec0 = new Node(4, sec1);

  // key number
  Node *key2 = new Node(3);
  Node *key1 = new Node(5, key2);
  Node *key0 = new Node(7, key1);

  Node *res = addTwoNumbers(first0, sec0);

  test(res, key0, 1);
}

void test2()
{
  // first number
  Node *first2 = new Node(9);
  Node *first1 = new Node(9, first2);
  Node *first0 = new Node(9, first1);

  // second number
  Node *sec1 = new Node(9);
  Node *sec0 = new Node(9, sec1);

  // key number
  Node *key3 = new Node(8);
  Node *key2 = new Node(9, key3);
  Node *key1 = new Node(0, key2);
  Node *key0 = new Node(1, key1);

  Node *res = addTwoNumbers(first0, sec0);

  test(res, key0, 2);
}

void test3()
{
  // first number
  Node *first2 = new Node(9);
  Node *first1 = new Node(9, first2);
  Node *first0 = new Node(9, first1);
  Node *first00 = new Node(9, first0);

  // second number
  Node *sec1 = new Node(9);
  Node *sec0 = new Node(9, sec1);

  // key number
  Node *key4 = new Node(8);
  Node *key3 = new Node(9, key4);
  Node *key2 = new Node(0, key3);
  Node *key1 = new Node(0, key2);
  Node *key0 = new Node(1, key1);

  Node *res = addTwoNumbers(first00, sec0);

  test(res, key0, 3);
}

int main()
{
  test1();
  test2();
  test3();
}
