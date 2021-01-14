// ---------------------------------------------------------------------------

#ifndef NodeListH
#define NodeListH

// ---------------------------------------------------------------------------
template<typename KT, typename DT> struct NodeList {
	KT key;
	DT value;
	bool used;
	NodeList<KT, DT> *next;
};
#endif
