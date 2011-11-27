#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER ust_tests_demo2

#if !defined(_TRACEPOINT_UST_TESTS_DEMO2_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_UST_TESTS_DEMO2_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Copyright (C) 2011  Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * THIS MATERIAL IS PROVIDED AS IS, WITH ABSOLUTELY NO WARRANTY EXPRESSED
 * OR IMPLIED.  ANY USE IS AT YOUR OWN RISK.
 *
 * Permission is hereby granted to use or copy this program
 * for any purpose,  provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 */

#include <lttng/tracepoint.h>

TRACEPOINT_LOGLEVEL_ENUM(
	tp_loglevel(other, 0)
	tp_loglevel(other2, 1)
	tp_loglevel(other3, 2)
)

TRACEPOINT_EVENT(ust_tests_demo2, loop,
	TP_ARGS(int, anint, int, netint, long *, values,
		 char *, text, size_t, textlen,
		 double, doublearg, float, floatarg),
	TP_FIELDS(
		ctf_integer(int, intfield, anint)
		ctf_integer_hex(int, intfield2, anint)
		ctf_integer(long, longfield, anint)
		ctf_integer_network(int, netintfield, netint)
		ctf_integer_network_hex(int, netintfieldhex, netint)
		ctf_array(long, arrfield1, values, 3)
		ctf_array_text(char, arrfield2, text, 10)
		ctf_sequence(char, seqfield1, text,
			     size_t, textlen)
		ctf_sequence_text(char, seqfield2, text,
			     size_t, textlen)
		ctf_string(stringfield, text)
		ctf_float(float, floatfield, floatarg)
		ctf_float(double, doublefield, doublearg)
	)
)
TRACEPOINT_LOGLEVEL(ust_tests_demo2, loop, other3)

#endif /* _TRACEPOINT_UST_TESTS_DEMO2_H */

#undef TRACEPOINT_INCLUDE_FILE
#define TRACEPOINT_INCLUDE_FILE ./ust_tests_demo2.h

/* This part must be outside ifdef protection */
#include <lttng/tracepoint-event.h>

#ifdef __cplusplus 
}
#endif
