# Late Binding in C++
## Differences between Java and C++ and how C++ overridden functions behave differently when you use objects or pointers to objects

The cool thing about Object Oriented Programming is that you can define methods in a base class that you can override to do something desirable in the overriding class. This is fairly common with GUI frameworks where you might have a `Drawable` with a `paint` method and then the `Circle` which extends the `Drawable` knows how to `paint` a circle and the `Box` which also extends `Drawable` knows how to `paint` a box with the framwork only having to call `paint` on whatever object it is working on. 

Consider this Java program:

```java
// FooBar.java
public abstract class FooBar {
    public abstract void doSomething();
};

// Foo.java
public class Foo extends FooBar {
    @Override
    public void doSomething() {
        System.out.println("Foo");
    }
};

// Bar.java
public class Bar extends FooBar {
    @Override
    public void doSomething() {
        System.out.println("Bar");
    }
};

// LateBinding.java
public class LateBinding {
    public static void main(String[] args) {
        Foo f = new Foo();
        Bar b = new Bar();
        FooBar fb;
        for (int i = 1; i <= 10; ++i) {
            int r = 1 + (int) (Math.random() * 10);
            if (r > 5) {
                fb = f;
            } else {
                fb = b;
            }
            fb.doSomething();
        }
    }
}
```

```
Output:
Foo
Bar
Foo
Foo
Foo
Bar
Bar
Foo
Bar
Bar
```

What's happening? Inside the for loop the program picks a random number between 1 and 10. If the number is larger
than 5 then our variable `fb` of type `FooBar` is set to the `Foo` type object `f`. If not then the `Bar` type
object `b` is assigned to the `FooBar` base class type variable `fb`. We then ask the object behind the `fb`
variable to `doSomething()`. Since the objects are either `Foo` or `Bar` objects they call the `doSomething()`
defined in the `Foo` overriding class or in the `Bar` overriding class and print Foo or Bar.


Let's do the same thing with C++:
```cpp
// EarlyBinding.cpp
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class FooBar {
public:
	virtual void doSomething() {
		std::cout << "FooBar\n";
	}
};

class Foo : public FooBar {
public:
	void doSomething() override {
		std::cout << "Foo\n";
	}
};

class Bar : public FooBar {
public:
	void doSomething() override	{
		std::cout << "Bar\n";
	}
};

int main() {
	Foo f;
	Bar b;
	FooBar fb;
	srand(time(NULL));
	for (auto i = 1; i <= 10; ++i) {
		auto r = rand() % 10 + 1;
		if (r > 5)
			fb = f;
		else
			fb = b;
		fb.doSomething();
	}
	return 0;
}
```

```
Output:
FooBar
FooBar
FooBar
FooBar
FooBar
FooBar
FooBar
FooBar
FooBar
FooBar
```
Try it yourself: <http://cpp.sh/454h4>

The result is spectacularly different! Why? When we push the `Foo` or `Bar` object into a `FooBar` variable we
essentially downcast our object to just the base functionality of the `FooBar` object. And when we call `FooBar`'s
`doSomething()` the compile-time VTable listed function `doSomething()` from `FooBar` is called.

Note that FooBar's doSomething function is a virtual function with an implementation. Importantly it is not a pure virtual function which would have a `= 0` at the end;

If we want the equivalent of the Java behaviour we need to use pointers. They use "late binding" and can figure out
at runtime what type of object they are dealing with and can call the appropriate function:

```cpp
// LateBinding.cpp
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class FooBar {
public:
	virtual void doSomething() {
		std::cout << "FooBar\n";
	}
};

class Foo : public FooBar {
public:
	void doSomething() override {
		std::cout << "Foo\n";
	}
};

class Bar : public FooBar {
public:
	void doSomething() override	{
		std::cout << "Bar\n";
	}
};

int main() {
	Foo f;
	Bar b;
	FooBar * fb;
	srand(time(NULL)); // seed randomizer
	for (auto i = 1; i <= 10; ++i) {
		auto r = rand() % 10 + 1;
		if (r > 5)
			fb = &f;
		else
			fb = &b;
		fb->doSomething();
	}
	return 0;
}
```

```
Output:
Bar
Bar
Foo
Bar
Foo
Foo
Foo
Bar
Foo
Bar
```
Check it: <http://cpp.sh/5ioi>

Note the subtle changes: `fb` is now a `FooBar` type pointer. We push a pointer to a `Foo` or `Bar` object into it. And when we call the `doSomething()` method the system understands what kind of object the pointer is pointing at and calls the overriding method in the sub-class.


See also:
<http://stackoverflow.com/questions/36691108/what-is-the-difference-between-early-binding-and-late-binding-in-c>


There is another twist to this C++ behaviour when a class's member function calls another member function which is marked virtual in the context of an extended object. Consider this code:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    virtual void foo() {
        cout << "foo from A" << endl;
    }
    void bar() {
        cout << "bar from A" << endl;
        foo();
    }
};

class B : public A {
public:
    void foo() {
        cout << "foo from B" << endl;
    }
};

int main()
{
  B b;
  b.bar();
}
```
Try it out: <http://cpp.sh/4nqzl>

The `bar` method which exists only on class A calls the `foo` method. But since `foo` on class A is a virtual method the function call is forwarded to the `foo` method in class B.

```
bar from A
foo from B
```

If class A's `foo` were not virtual then `bar` would call `foo` from class A:
```cpp
#include <iostream>
using namespace std;

class A {
public:
    void foo() {
        cout << "foo from A" << endl;
    }
    void bar() {
        cout << "bar from A" << endl;
        foo();
    }
};

class B : public A {
public:
    void foo() {
        cout << "foo from B" << endl;
    }
};

int main()
{
  B b;
  b.bar();
}
```

```
bar from A
foo from A
```

Try it out: <http://cpp.sh/74osp>
