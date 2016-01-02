package stack

import (
  "testing"
)

func TestStack(t *testing.T){
  stack := NewStack()
  if !stack.IsEmpty(){
    t.Fail()
  }

  item := "hello"
  stack.Push(item)
  if stack.Size() != 1{
    t.Fail()
  }

  popItem := stack.Pop()
  if item != popItem {
    t.Fail()
  }

  if !stack.IsEmpty(){
    t.Fail()
  }
}
