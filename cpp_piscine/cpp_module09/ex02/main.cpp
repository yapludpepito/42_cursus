#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
	{
		std::cout << "no enough arg\n";
        return (0);
	}
	try 
	{
		clock_t t = clock();
		std::cout << "List before sort : ";
		std::vector<int> lst = PmergeMe::get_list(argc, argv);
		PmergeMe::print_list(lst);
		lst = PmergeMe::ft_merge_insert_sort(lst);
		double time1 = (static_cast<double>(clock() - t) / CLOCKS_PER_SEC * 1000000);
		t = clock();
		std::list<int> lst1 = PmergeMe::get_list_for_list(argc, argv);
		lst1 = PmergeMe::ft_merge_insert_sort_for_list(lst1);
		std::cout << "list after sort : ";
		PmergeMe::print_list(lst1);
		std::cout << "time for vector : " << time1 << " microseconde " <<std::endl;
		std::cout << "time for lst : " << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC * 1000000) << " microseconde " <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}