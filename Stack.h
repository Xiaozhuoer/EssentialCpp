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

        //查找栈里是否有elem
        bool find(std::string &elem){
            //栈不为空的时候
            while(!_stack.empty()){
                //elem和栈顶元素对比
                if(_contrast(elem)){
                    //将所有交换栈里的元素压进原栈
                    _swap_all_pop();
                    return true;
                }else{
                    //false
                    //将原栈栈顶元素压进交换栈
                    _swap_push();
                }
            }
            //执行到这说明原栈里没找到elem
            _swap_all_pop();
            return false;
        }

        //返回某字符串出现的次数
        int count(std::string &str){
            int count = 0;
            //栈不为空的时候
            while(!_stack.empty()){
                //elem和栈顶元素对比
                //对比
                if(_contrast(str)){
                    count++;
                }
                _swap_push();
            }
            _swap_all_pop();

            return count;
            
        }
        
    private:
        std::vector<std::string> _stack;
        std::vector<std::string> _stack_swap;
        std::string elem_swap;
        bool flag = false;

        //将交换栈的元素弹出并压进原栈
        void _swap_all_pop(){
            while(!_stack_swap.empty()){
                _stack.push_back(_stack_swap.back());
                _stack_swap.pop_back();
            }
        }
        //将原栈元素弹出并压进交换栈
        void _swap_push(){
            _stack_swap.push_back(_stack.back());
            _stack.pop_back();
        }
        //对比
        bool _contrast(std::string &elem){
            return elem == _stack.back() ? true : false;
        }

};