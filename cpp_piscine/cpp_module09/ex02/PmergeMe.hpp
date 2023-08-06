#ifndef __PMERGEME_H__
#define __PMERGEME_H__

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>

class PmergeMe
{
    private :
        PmergeMe();
        PmergeMe(const PmergeMe &target);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe &target);
    public : 
        static void	print_list(std::vector<int> &lst);
        static void	print_list(std::list<int> &lst);
        static std::vector<int>	get_list(unsigned int argc, char *argv[]);
        static std::vector<int>	ft_merge(std::vector<int> lst, std::vector<std::vector<int> > &tab);
        static std::vector<int>	ft_merge_insert_sort(std::vector<int> lst);
        static std::list<int>	get_list_for_list(unsigned int argc, char *argv[]);
        static std::list<int>	ft_merge_for_list(std::list<int> lst, std::list<std::list<int> > &tab);
        static std::list<int>	ft_merge_insert_sort_for_list(std::list<int> lst);

};


#endif // __PMERGEME_H__