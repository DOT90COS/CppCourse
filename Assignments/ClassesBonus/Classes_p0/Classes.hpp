#pragma once

#include <cstdint>
#include <vector>
#include <deque>
#include <memory>
#include <string>

enum class ValueType {
	TypeInt,
	TypeString,
	TypeDouble,
};

class IValue {
public:
	~IValue() {}
	virtual ValueType getType() const = 0;
	virtual int getInt() = 0;
	virtual std::string getString() = 0;
	virtual double getDouble() = 0;
	virtual int operator+(int) = 0;
	virtual double operator+(double) = 0;
	virtual std::string operator+(std::string) = 0;
	
};

class IStack {
public:
	~IStack() {}
	virtual void push(std::shared_ptr<IValue>&&) = 0;
	virtual std::shared_ptr<IValue> pop() = 0;
	virtual uint32_t count() const = 0;

};

/*
have to implement a generic interface that can take an int, a double, or a string
overload operator+
and then implement a stack with push and pop
that will accept the new variant type
my solution used a union, but
anything should work 😛
*/


// TODO: Implement Value and Stack
std::shared_ptr<IValue> make_value(int x) { return std::make_shared<Value>(x); }
std::shared_ptr<IValue> make_value(double x) { return std::make_shared<Value>(x); }
std::shared_ptr<IValue> make_value(std::string x) { return std::make_shared<Value>(x); }


std::unique_ptr<IStack> make_stack() { return std::make_unique<Stack>(); }