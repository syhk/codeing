#include "iostream"

using namespace std;

class Invoice {
 public:
  virtual void printInvoice() {
    cout << "This is the content of the invoice!" << endl;
  }
};

class Decorator : public Invoice {
  Invoice *ticket;

 public:
  Decorator(Invoice *t) { ticket = t; }

  void printInvoice() {
    if (ticket != nullptr) ticket->printInvoice();
  }
};

class HeadDecorator : public Decorator {
 public:
  HeadDecorator(Invoice *t) : Decorator(t) {}
  void printInvoice() {
    cout << "This is the header of the invoice!" << endl;
    Decorator::printInvoice();
  }
};

class FootDecorator : public Decorator {
 public:
  FootDecorator(Invoice *t) : Decorator(t) {}
  void printInvoice() {
    Decorator::printInvoice();
    cout << "This is the footnote of the invoice!" << endl;
  }
};

int main(void) {
  Invoice t;
  FootDecorator f(&t);
  HeadDecorator h(&f);
  h.printInvoice();
  cout << "------------------------" << endl;
  FootDecorator a(nullptr);
  HeadDecorator b(&a);
  b.printInvoice();
  return 0;
}
