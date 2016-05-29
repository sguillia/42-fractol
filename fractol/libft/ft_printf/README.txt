~~~ ft_printf ~~~
December 2015
sguillia@student.42.fr

Fixed bugs since push/clone :
- No leaks anymore in handle_nonmodulo

Non-fixed bugs found after push/clone :
- Precision for %ls cuts after X bytes, not X wide characters
- (%c, '\0') doesn't call ft_putchar('\0'), but it should;
	Try : ("{%c}", '\0') | cat -e

Bonuses are :

*
$
colors
%b %#b
%r
%P %B



MFW = minimum field width

----------------------------
--- 1. ---------------------
* for MFW
*x$ for MFW
--- 2. ---------------------
.* for precision
.*x$ for precision
--- 3. ---------------------
%red;
%yellow;
%green;
%blue;
%magenta;
%cyan;
%;		== reset color
--- 4. ---------------------
%b = print binary
%#b = print binary as 0b...
--- 5. ---------------------
%r = print string replacing non-printable characters by '.' (including \n)
--- 6.---------------------
%B %P = print to uppercase
----------------------------



Additional info :
ft_uintmaxtoa_bas.c should be called ft_uintmaxtoa_base.c
The 'e' has been omitted because of a norminette bug at the time I'm writing
