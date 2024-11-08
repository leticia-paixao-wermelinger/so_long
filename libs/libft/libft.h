
#ifndef LIBFT_H 
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

int					my_atoi(const char *nptr);
void				my_bzero(void *s, size_t n);
void				*my_calloc(size_t nmemb, size_t size);
int					my_isalnum(int c);
int					my_isalpha(int c);
int					my_isascii(int c);
int					my_isdigit(int c);
int					my_isprint(int c);
char				*my_itoa(int n);
void				*my_memchr(const void *s, int c, size_t n);
int					my_memcmp(const void *s1, const void *s2, size_t n);
void				*my_memcpy(void *dest, const void *src, size_t n);
void				*my_memmove(void *dest, const void *src, size_t n);
void				*my_memset(void *s, int c, size_t n);
int					my_printf(const char *str, ...);
int					my_putchar(char c);
void				my_putchar_fd(char c, int fd);
void				my_putendl_fd(char *s, int fd);
int					my_putnbr(int n);
int					my_putnbr_base(unsigned long int n, int max_base, char c);
void				my_putnbr_fd(int n, int fd);
int					my_putstr(char *s);
void				my_putstr_fd(char *s, int fd);
char				**my_split(char const *s, char c);
void				my_clean_vect(char **vect);
char				*my_strchr(const char *s, int c);
char				*my_strdup(const char *s);
void				my_striteri(char *s, void (*f)(unsigned int, char *));
char				*my_strjoin(char const *s1, char const *s2);
size_t				my_strlcat(char *dst, const char *src, size_t size);
size_t				my_strlcpy(char *dst, const char *src, size_t size);
size_t				my_strlen(const char *s);
char				*my_strmapi(char const *s, char (*f)(unsigned int, char));
int					my_strncmp(const char *s1, const char *s2, size_t n);
char				*my_strnstr(const char *big, const char *little, \
			size_t len);
char				*my_strrchr(const char *s, int c);
char				*my_strtrim(char const *s1, char const *set);
char				*my_substr(char const *s, unsigned int start, size_t len);
int					my_tolower(int c);
int					my_toupper(int c);
long unsigned int	gnl_ft_strlen(const char *str);
char				*gnl_ft_strchr(const char *s, int c);
int					gnl_my_strchr(const char *s, int c);
char				*gnl_ft_strjoin(char *s1, char *s2);
char				*gnl_my_join(char *s1, char *s2, char *string);
char				*gnl_ft_substr(char const *s, unsigned int start, \
			size_t len);
char				*get_next_line(int fd);
#endif
