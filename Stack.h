#include <string>
#include <vector>

class Stack{
    public:

        //压栈
        bool push(const std::string &elem ){
            if(full()){
                return false;
            }
            _stack.push_back(elem);
            return true;
        }

        //栈顶元素弹出, 并取得栈顶元素的引用
        bool pop(std::string &elem){
            if(empty()){
                return false;
            }
            elem = _stack.back();
            _stack.pop_back();
            return true;
        }

        //取得栈顶元素的引用
        bool peek(std::string &elem){
            if(empty()){
                return false;
            }
            elem = _stack.back();
            return true;
        }

        //查询栈是否为空
        bool empty(){
            return _stack.empty();
        }

        //查询栈是否满
        bool full(){
            return _stack.size() == _stack.max_size();
        }

        //查询栈目前的大小
        int size(){
            return _stack.size();
        }

    private:
        std::vector<std::string> _stack;

};