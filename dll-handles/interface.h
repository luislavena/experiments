#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#ifndef API_EXTERN
# define API_EXTERN extern
#endif

API_EXTERN void load_extension(char *);
API_EXTERN void call_me(void);

#endif /* _INTERFACE_H_ */
