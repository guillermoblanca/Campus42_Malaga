/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanca- <gblanca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:08:52 by gblanca-          #+#    #+#             */
/*   Updated: 2024/04/16 18:38:29 by gblanca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/**
 * @struct s_list
 * Represents a node in a linked list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/// @brief 
///Check if the value is a number between '0' or '9' based on ASCII code (48-57)
/// @param c 
/// @return 1 if is a digit or 0 if not
int		ft_isdigit(int c);

/// @brief Checks if a char value is between (32-126) 
///range for printing based on ASCII code
/// @param c 
/// @return 
int		ft_isprint(int c);

/// @brief 
///Checks if a char value is between (0-127) 
///range for printing based on ASCII code
/// @param c 
/// @return 
int		ft_isascii(int c);

/// @brief 
///Checks if the value is lower casse or up case in the range of (a-z) or (A-Z)
/// @param c 
/// @return 1 if is (a-z) 2 if is (A-Z) and (0) if is not any of them
int		ft_isalpha(int c);

/// @brief 
///Checks that the value is alphanumeric character (0-9) || (a-z) || (A-Z)
/// @param c 
/// @return 1 if is upper casse 2 if lower case 3 if is a digit
int		ft_isalnum(int c);

/// @brief 
///Converts if is alnum  to uppercase
/// @param c 
/// @return 1 if is lower casse 2 if upper case 3 if is a digit
int		ft_toupper(int c);

/// @brief 
///Converts if is alnum  to lower casse
/// @param c 
/// @return 1 if is lower casse 2 if upper case 3 if is a digit
int		ft_tolower(int c);

///@brief 
///Writes the len bytes of value c (converted to unsigned char) 
///to the b parameter. Use char for byte transformation 
/// because the function use unsigned char as the transformation value
/// @param b 
/// @param c 
/// @param len 
/// @return return the pointer to the first element of b. 
void	*ft_memset(void *b, int c, size_t len);

/// @brief search in unsigned char to find c value in size_t n
/// @param s 
/// @param c 
/// @param n 
/// @return 
void	*ft_memchr(const void *s, int c, size_t n);

/// @brief Works like memset except you don't have to specify 
///what byte to write, it'll always be 0
/// @param s pointer to the value that will be written with '\0'
/// @param n the lenght of s
void	ft_bzero(void *s, size_t n);

/// @brief Copies maximum n bytes from src to dst 
/// @param dst destination of the copy requires a minimum sizeof n to be copied
/// @param src source to be copied in dst
/// @param n the number of bytes that will be copied
/// @return 
void	*ft_memcpy(void *dst, const void *src, size_t n);

/// @brief Copies len bytes form string src to string dst. 
/// The copy is always done in a non-destructive manner
/// @param dst 
/// @param src 
/// @param len 
/// @return the original value of dst
void	*ft_memmove(void *dst, const void *src, size_t len);

///@brief compares byte string s1 agains byte string s2. 
///assumed to be n bytes long
///@param s1 first str 
///@param s2 second str
///@param n number of bytes to compare
///@return zero if the two strings are identical otherwise
/// returns the difference between the first two differing bytes
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/// @brief find the lenght of a string. the string cannot be modified
/// @param s 
/// @return the number of characters that precede the terminating NULL
/// character (\0)
size_t	ft_strlen(const char *s);

/// @brief returns a str at the beginning of the ascii value   
/// @param str string to iterate
/// @param c ascii value to search
/// @return the new str at the beginning of c
/// character (\0)
char	*ft_strchr(const char *str, int c);

/// @brief returns a str at the last of the ascii value   
/// @param s string to iterate
/// @param c ascii value to search
/// @return the new str the last of c
/// character (\0)
char	*ft_strrchr(const char *s, int c);

///@brief compares two strings and return the diff value s1 - s2
///@param s1 first str
///@param s2 second str
///@result return the diff value between to strings and the size of
int		ft_strncmp(const char *s1, const char *s2, size_t n);

///@brief copies the src to dst value 
///@param dst the str buffer to be copied
///@param src str source copied
///@param dstsize number of bytes copied to dst
///@return return the size of the src 
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

///@brief concadenates  src to the final dst
///@param dst str requires to reserve space with null termination to add src
///@param src the str to be copied at dst
///@param dstsize the amount of bytes to be copied 
///@return the size of the dst characters dst size + src copied 
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

///@brief 
///finds in src the string in tofind if tofind is empty src is returned 
///if tofind is not found NULL is returned
///@param src the string to search of
///@param tofind the string to find
///@param len number of characters to look for in src
///@return the string in the index of the first index of the finded word
char	*ft_strnstr(const char *src, const char *tofind, size_t len);

/// @brief 
/// @param s 
/// @param c 
/// @return 
char	**ft_split(char const *s, char c);
/// @brief creates a new str from the start index with the len size
/// @param  s string for creation
/// @param start index of the s to start copying
/// @param len size of the substring
/// @return result substring NULL if memory failed
char	*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief creates a new str with s1 appended to s2
/// @param s1 first str
/// @param s2 first str
/// @return new str or NULL value
char	*ft_strjoin(char const *s1, char const *s2);

/// @brief return a new string with the removed characters of set
/// @param s1 the string to be trim 
/// @param s2 characters to trim
/// @return new str or NULL value if memory reserve fails
char	*ft_strtrim(char const *s1, char const *set);

/// @brief Initializes a pointer with default values to zero
///can return NULL of no memory available
/// @param num number of elements
/// @param size sizeof bytes
/// @return pointer of any type with defaults values 
void	*ft_calloc(size_t num, size_t size);

/// @brief 	Duplicates the str to a new one. can return NULL
/// @param str string to copy
/// @return new str 
char	*ft_strdup(const char *str);

/// @brief converts str to int finding the '0' - '9' digits
///spaces, tabs, and new lines works
///only one symbol is checked
/// @param str string to find
/// @returns int return value, 0 if not founded any number or there is a error
int		ft_atoi(const char *str);
/**
 * Converts an integer to a string.
 *
 * @param n The integer to convert.
 * @return The string representation of the integer.
 */
char	*ft_itoa(int n);

/**
 * Writes a character to the specified file descriptor.
 *
 * @param c The character to be written.
 * @param fd The file descriptor to write the character to.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * Writes the string `s` followed by a newline character ('\n') to the file
 * descriptor `fd`.
 *
 * @param s The string to be written.
 * @param fd The file descriptor to write to.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * Writes the integer 'n' to the file descriptor 'fd'.
 *
 * @param n The integer to be written.
 * @param fd The file descriptor to write to.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * Writes the string `s` to the file descriptor `fd`.
 *
 * @param s The string to be written.
 * @param fd The file descriptor to write to.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * Applies the function `f` to each character of the string `s`,
 * passing its index as the first argument.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/// @brief Applies a function to each character of a string, 
///creating a new string with the results.
/// @param s The string to iterate through.
/// @param f The function to apply to each character. 
//The function takes the index of the character as a parameter.
/// @return The new string created by applying the function to each character
/// of the original string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * Adds the element 'new' at the end of the linked list 'lst'.
 *
 * @param lst The address of a pointer to the first element of the list.
 * @param new The element to add at the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Adds the given element `new` at the beginning of the linked list `lst`.
 *
 * @param lst The address of a pointer to the first node of the linked list.
 * @param new The node to be added at the front of the linked list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Clears a linked list by deleting all of its nodes and freeing the memory.
 *
 * @param lst The address of a pointer to the first node of the linked list.
 * @param del The function used to delete the content of each node.
 *            This function is called with the content of
 * 			  each node as its parameter.
 *            If the parameter is NULL, no deletion is performed.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * Deletes a single node from a linked list.
 *
 * This function deletes the specified node `lst` from the linked list.
 * The `del` function is used to free the memory 
 * occupied by the content of the node.
 *
 * @param lst The node to be deleted.
 * @param del The function used to delete the content of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * Applies the function `f` to each element of the linked list `lst`.
 *
 * @param lst The linked list to iterate over.
 * @param f   The function to apply to each element of the linked list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Returns the last element of a linked list.
 *
 * @param lst The pointer to the head of the linked list.
 * @return The pointer to the last element of the linked list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * Applies the function `f` to each element of the linked
 *  list `lst` and creates a new
 * list resulting from the successive applications of `f`.
 *  The `del` function is used
 * to delete the content of an element if needed.
 *
 * @param lst The pointer to the first element of the linked list.
 * @param f A pointer to the function to apply to each element
 *  of the linked list.
 *          This function should take a void pointer as a parameterç
 *  and return a void pointer.
 * @param del A pointer to the function used to delete the content
 *  of an element if needed.
 *            This function should take a void pointer as a
 *  parameter and return nothing.
 * @return The new linked list created by applying `f` to each element of `lst`.
 *         If an allocation fails, the function returns NULL.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));

/**
 * Creates a new linked list node with the specified content.
 *
 * @param content The content to be stored in the new node.
 * @return A pointer to the newly created node,
 *  or NULL if memory allocation fails.
 */
t_list	*ft_lstnew(void *content);

/**
 * Returns the number of elements in a linked list.
 *
 * @param lst The pointer to the head of the linked list.
 * @return The number of elements in the linked list.
 */
int		ft_lstsize(t_list *lst);
#endif