/*
 * This file and its contents are supplied under the terms of the
 * Common Development and Distribution License ("CDDL"), version 1.0.
 * You may only use this file in accordance with the terms of version
 * 1.0 of the CDDL.
 *
 * A full copy of the text of the CDDL should have accompanied this
 * source.  A copy of the CDDL is also available via the Internet at
 * http://www.illumos.org/license/CDDL.
 */

/*
 * Copyright 2015 Joyent, Inc.  All rights reserved.
 */

#ifndef _SYS__LX_MISC_H
#define	_SYS__LX_MISC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <sys/lx_brand.h>

#ifdef _KERNEL

extern void lx_setrval(klwp_t *, int, int);
extern void lx_exec();
extern void lx_exitlwp(klwp_t *);
extern void lx_freelwp(klwp_t *);
extern int lx_initlwp(klwp_t *);
extern void lx_forklwp(klwp_t *, klwp_t *);

extern void lx_set_gdt(int, user_desc_t *);
extern void lx_clear_gdt(int);

extern longlong_t lx_nosys();

extern greg_t lx_fixsegreg(greg_t, model_t);
extern uintptr_t lx_fsbase(klwp_t *, uintptr_t);
extern void lx_exit_with_sig(proc_t *, sigqueue_t *, void *);
extern boolean_t lx_wait_filter(proc_t *, proc_t *);

#define	LX_IFNAME_FROMNATIVE	0
#define	LX_IFNAME_TONATIVE	1

extern void lx_ifname_convert(char *, int);

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS__LX_MISC_H */