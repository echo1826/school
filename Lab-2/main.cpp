// using c++20
#include <iostream>
#include <cassert>
#include <string>
#include <cctype>

using namespace std;

template<typename T>
class StackADT {
public:
    virtual bool isEmpty() const = 0;

    virtual void push(const T& value) = 0;
    virtual T peek() const = 0;
    virtual bool pop() = 0;
};

constexpr int MIN_ARRAY_SIZE = 64;

template<typename T, int N>
class ArrayStack final : StackADT<T> {
private:
    int topIndex;
    int array[N]{};
public:
    ArrayStack() : topIndex(-1) {
        static_assert(N >= MIN_ARRAY_SIZE);
    }

    bool isEmpty() const override {
        // TODO
        return topIndex < 0;
    }

    void push(const T& value) override {
        if (topIndex == N) {
            throw std::length_error("Max array exceeded.");
        }
        // TODO
        topIndex++;
        array[topIndex] = value;
    }

    T peek() const override {
        if (isEmpty()) {
            throw std::logic_error("Peek on empty ArrayStack.");
        }

        // TODO
        return array[topIndex];
    }

    bool pop() override {
        if (isEmpty()) {
            return false;
        }
        // TODO
        topIndex--;
        return true;
    }
};

void testArrayStack() {
    ArrayStack<int, MIN_ARRAY_SIZE> stack0;
    std::cout << stack0.isEmpty();
    assert(stack0.isEmpty());
    stack0.push(10);
    assert(stack0.peek() == 10);
    stack0.push(20);
    assert(stack0.peek() == 20);
    assert(stack0.pop());
    assert(stack0.peek() == 10);
    assert(stack0.pop());
    assert(stack0.isEmpty());
}

template<typename T>
class Node {
private:
    T value;
    Node* next;

public:
    Node(T value) : value(value), next(nullptr) {}
    Node(T value, Node* next) : value(value), next(next) {}

    T getValue() const {
        return value;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* n) {
        next = n;
    }

    void setValue(const T& v) {
        value = v;
    }
};

template<typename T>
class ListStack : public StackADT<T> {
private:
    Node<T>* top;
public:
    ListStack() : top(nullptr) {}
    ~ListStack() {
        while (pop()) {}
    }

    // Copy constructor
    ListStack(const ListStack& other) {
        // TODO
        Node<T>* originalStackPointer = other.top;
        if (originalStackPointer == nullptr) {
            top = nullptr;
        }
        else {
            top = new Node<T>(originalStackPointer->getValue());
            Node<T>* newStackPointer = top;
            originalStackPointer = originalStackPointer->getNext();
            while (originalStackPointer != nullptr) {
                T nextValue = originalStackPointer->getValue();
                Node<T>* newNodePointer = new Node<T>(nextValue);
                newStackPointer->setNext(newNodePointer);
                newStackPointer = newStackPointer->getNext();
                originalStackPointer = originalStackPointer->getNext();
            }
            newStackPointer->setNext(nullptr);
        }
    }

    // Copy move constructor, Hint: Don't forget to make a "hollow" data structure.
    ListStack(ListStack&& other) noexcept {
        // TODO
    }

    bool isEmpty() const override {
        // TODO
        return top == nullptr;
    }

    void push(const T& value) override {
        // TODO
        Node<T>* newNode = new Node<T>(value, top);
        top = newNode;
    }

    T peek() const override {
        if (isEmpty()) {
            throw std::logic_error("Peek on empty ArrayStack.");
        }

        // TODO
        return top->getValue();
    }

    bool pop() override {
        if (isEmpty()) {
            return false;
        }

        // TODO
        Node<T>* deleteNode = top;
        top = top->getNext();
        deleteNode->setNext(nullptr);
        delete deleteNode;
        deleteNode = nullptr;
        return true;
    }
};

void testListStack() {
    ListStack<int> stack0;
    assert(stack0.isEmpty());
    stack0.push(10);
    assert(stack0.peek() == 10);
    stack0.push(20);
    assert(stack0.peek() == 20);
    assert(stack0.pop());
    assert(stack0.peek() == 10);
    assert(stack0.pop());
    assert(stack0.isEmpty());

    // Test copy constructor
    stack0.push(1);
    stack0.push(2);
    stack0.push(3);

    ListStack<int> stack1(stack0);
    assert(!stack0.isEmpty());
    assert(stack0.peek() == 3);
    assert(!stack1.isEmpty());
    assert(stack1.peek() == 3);

    // Test move constructor.
    /*ListStack<int> stack2(std::move(stack0));
    assert(stack0.isEmpty());
    assert(!stack2.isEmpty());
    assert(stack2.peek() == 3);*/
}

bool areCurleyBracesMatched(const string& inputString) {
    // TODO
    return false;
}

void testAreCurleyBracesMatched() {
    assert(areCurleyBracesMatched(""));
    assert(areCurleyBracesMatched("{}"));
    assert(areCurleyBracesMatched("a{bc}d"));
    assert(!areCurleyBracesMatched("{"));
    assert(!areCurleyBracesMatched("}"));
    assert(!areCurleyBracesMatched("a{b{c}"));
};

bool isPalindrome(const string& inputString) {
    // TODO
    return false;
}

void testIsPalindrome() {
    assert(isPalindrome(""));
    assert(isPalindrome("a"));
    assert(isPalindrome("aa"));
    assert(isPalindrome("aba"));
    assert(isPalindrome("abba"));
    assert(!isPalindrome("ab"));
    assert(!isPalindrome("abaa"));
}

string reversedString(const string& inputString) {
    // TODO
    return {};
}

void testReversedString() {
    assert(reversedString("").empty());
    assert(reversedString("a") == "a");
    assert(reversedString("ab") == "ba");
    assert(reversedString("abc") == "cba");
}

// Helper for infixToPostFix.
int precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    else {
        assert(op == '+' || op == '-');
        return 1;
    }
}

// Helper for infixToPostFix.
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Helper for infixToPostFix.
bool isOperand(char ch) {
    return isalpha(ch);
}

string infixToPostFix(const string& infix) {
    // TODO
    return {};
}

void testInfixToPostFix() {
    assert(infixToPostFix("").empty());

    assert(infixToPostFix("a") == "a");
    assert(infixToPostFix("a+b") == "ab+");
    assert(infixToPostFix("a*b") == "ab*");

    assert(infixToPostFix("a+b*c") == "abc*+");
    assert(infixToPostFix("a+(b*c)") == "abc*+");
    assert(infixToPostFix("(a+(b*c))") == "abc*+");

    assert(infixToPostFix("(a+b)*c") == "ab+c*");
    assert(infixToPostFix("((a+b)*c)") == "ab+c*");

    assert(infixToPostFix("a*b+c") == "ab*c+");
    assert(infixToPostFix("(a*b)+c") == "ab*c+");
    assert(infixToPostFix("((a*b)+c)") == "ab*c+");
}

int main() {
    testArrayStack();
    testListStack();
    testAreCurleyBracesMatched();
    testIsPalindrome();
    testReversedString();
    testInfixToPostFix();
    return 0;
}

