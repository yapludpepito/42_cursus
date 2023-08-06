#ifndef __RPN_H__
#define __RPN_H__

#include <iostream>
#include <stack>

class RPN {
    private :
        RPN();
        RPN(RPN &target);
        RPN &operator=(RPN &target);
        ~RPN();
    public :
        static void calculation(std::string input);
};

#endif // __RPN_H__