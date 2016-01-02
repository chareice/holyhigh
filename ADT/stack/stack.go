package stack

type Stack struct{
  payload []interface{}
}

func (s *Stack) Push(item interface{}){
  s.payload = append(s.payload, item)
}

func (s *Stack)  Pop() interface{}{
  lastItem := s.payload[len(s.payload)-1]
  s.payload = s.payload[:len(s.payload)-1]
  return lastItem
}

func (s *Stack) IsEmpty() bool{
  return s.Size() == 0
}

func (s *Stack) Size() int{
  return len(s.payload)
}

func NewStack() *Stack{
  stack := Stack{}
  return &stack
}
