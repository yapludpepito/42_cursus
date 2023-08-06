#include "PmergeMe.hpp"

void	PmergeMe::print_list(std::vector<int> &lst)
{
	int i = 0;
	std::vector<int>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		i++;
		if (i == 4)
			break ;
		std::cout << *it << " ";

	}
	if (it != lst.end())
		std::cout << "[...]";	
	std::cout << std::endl;
}


void	PmergeMe::print_list(std::list<int> &lst)
{
	int i = 0;
	std::list<int>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		i++;
		if (i == 4)
			break ;
		std::cout << *it << " ";
	}
	if (it != lst.end())
		std::cout << "[...]";	
	std::cout << std::endl;
}


//for vector
std::vector<int>	PmergeMe::get_list(unsigned int argc, char *argv[])
{
	std::vector<int> lst;
	for (unsigned int i = 1; i < argc; i++) {
		std::stringstream	ss;
		int					n;
		unsigned int		j = 0;
		std::string			arg = argv[i];
		if (argv[i][0] == '\0')
			throw std::invalid_argument("invalid arg");
		if (arg[0] == '-')
			throw std::invalid_argument("invalid arg");
		while (j < arg.size() && std::isdigit(arg[j]))
			j++;
		if (j != arg.size())
			throw std::invalid_argument("invalid arg");
		ss << arg;
		ss >> n;
		lst.push_back(n);
	}
	return (lst);
}

std::vector<int>	PmergeMe::ft_merge(std::vector<int> lst, std::vector<std::vector<int> > &tab)
{
	std::vector<int> a;

	for (int i = 0; i < 4; i++)
	{
		a.push_back(*(lst.end() - 1));
		lst.pop_back();
	}
	tab.push_back(a);
	return (lst);
}

std::vector<int>	PmergeMe::ft_merge_insert_sort(std::vector<int> lst)
{
	std::vector<std::vector<int> > tab;
	std::vector<int> result;
	long unsigned int result_size = lst.size();
	int number = 2147483647;
	while (lst.size() > 4)
		lst = ft_merge(lst, tab);
	tab.push_back(lst);
	for (std::vector<std::vector<int> >::iterator it = tab.begin(); it < tab.end(); it++)
	{
		std::sort((*it).begin(), (*it).end());
		std::reverse((*it).begin(), (*it).end());
	}
	while (result_size != result.size())
	{
		std::vector<std::vector<int> >::iterator save_big;
		std::vector<int>::iterator save;
		for (std::vector<std::vector<int> >::iterator it = tab.begin(); it < tab.end(); it++)
		{
			if ((*it).size() > 0 && (*((*it).end() - 1) ) <= number)
			{
				save_big = it;
				save = (*it).end() - 1;
				number = *((*it).end() - 1); 
			}
		}
		result.push_back(*save);
		(*save_big).pop_back();
		number = 2147483647;
	}
	return (result);
}

// for lst
std::list<int>	PmergeMe::get_list_for_list(unsigned int argc, char *argv[])
{
	std::list<int> lst;
	for (unsigned int i = 1; i < argc; i++) {
		std::stringstream	ss;
		int					n;
		unsigned int		j = 0;
		std::string			arg = argv[i];
		if (arg[0] == '-')
			j++;
		while (j < arg.size() && std::isdigit(arg[j]))
			j++;
		if (j != arg.size())
			throw std::invalid_argument("invalid arg");
		ss << arg;
		ss >> n;
		lst.push_back(n);
	}
	return (lst);
}

std::list<int>	PmergeMe::ft_merge_for_list(std::list<int> lst, std::list<std::list<int> > &tab)
{
	std::list<int> a;

	for (int i = 0; i < 4; i++)
	{
		a.push_back(*(--lst.end()));
		lst.pop_back();
	}
	tab.push_back(a);
	return (lst);
}

std::list<int>	PmergeMe::ft_merge_insert_sort_for_list(std::list<int> lst)
{
	std::list<std::list<int> > tab;
	std::list<int> result;
	long unsigned int result_size = lst.size();
	int number = 2147483647;
	while (lst.size() > 4)
		lst = ft_merge_for_list(lst, tab);
	tab.push_back(lst);
	for (std::list<std::list<int> >::iterator it = tab.begin(); it != tab.end(); it++)
	{
		(*it).sort();
		(*it).reverse();
	}
	while (result_size != result.size())
	{
		std::list<std::list<int> >::iterator save_big;
		int save;
		for (std::list<std::list<int> >::iterator it = tab.begin(); it != tab.end(); it++)
		{
			if ((*it).size() > 0 && (*it).back() <= number)
			{
				save_big = it;
				save = (*it).back();
				number = save; 
			}
		}
		result.push_back(save);
		(*save_big).pop_back();
		number = 2147483647;
	}
	return (result);
}

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe &target)
{
    (void)target;
}

PmergeMe::~PmergeMe()
{
    
}

PmergeMe& PmergeMe::operator=(PmergeMe &target)
{
    (void)target;
    return (*this);
}
