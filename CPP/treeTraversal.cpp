#include <iostream>

struct	tree {
	char	left = '\0';
	char	right = '\0';
	char	value = '\0';
};

tree	arr[26];

void	letsPreorder(tree t)
{
	std::cout << t.value;
	if (t.left && t.left != '.')
		letsPreorder(arr[t.left - 'A']);
	if (t.right && t.right != '.')
		letsPreorder(arr[t.right - 'A']);
}

void	letsInorder(tree t)
{
	if (t.left && t.left != '.')
		letsInorder(arr[t.left - 'A']);
	std::cout << t.value;
	if (t.right && t.right != '.')
		letsInorder(arr[t.right - 'A']);
}

void	letsPostorder(tree t)
{
	if (t.left && t.left != '.')
		letsPostorder(arr[t.left - 'A']);
	if (t.right && t.right != '.')
		letsPostorder(arr[t.right - 'A']);
	std::cout << t.value;

}

int	main(void)
{
	int	n;
	std::cin >> n;

	char	parent, l, r;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> parent >> l >> r;
		arr[parent - 'A'].value = parent;
		arr[parent - 'A'].left = l;
		arr[parent - 'A'].right = r;
	}

	letsPreorder(arr[0]);
	std::cout << '\n';
	letsInorder(arr[0]);
	std::cout << '\n';
	letsPostorder(arr[0]);
	std::cout << '\n';
	return 0;
}
