#include "pch-cpp.hpp"






struct Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588;
struct List_1_tFE70423E15F3F797BC0F99DCA699342A89DB00BA;
struct JsonObject_t406D6CED608F0168281B11ABEBEFACB5DE6B471C;
struct ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66;
struct ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1;
struct String_t;



IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CPrivateImplementationDetailsU3E_t0628EC2558B8C9A382347E3EE1F74322D04C3AC7  : public RuntimeObject
{
};
struct JsonNode_t89D576EB46FFB3284319983B041AB01B7518C73D  : public RuntimeObject
{
};
struct ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66  : public RuntimeObject
{
	String_t* ___U3CRequestIdU3Ek__BackingField;
	String_t* ___U3CMethodU3Ek__BackingField;
	JsonObject_t406D6CED608F0168281B11ABEBEFACB5DE6B471C* ___U3CParamsU3Ek__BackingField;
};
struct ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1  : public RuntimeObject
{
	String_t* ___U3CRequestIdU3Ek__BackingField;
	bool ___U3CSuccessU3Ek__BackingField;
	RuntimeObject* ___U3CResultU3Ek__BackingField;
	String_t* ___U3CErrorU3Ek__BackingField;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct JsonObject_t406D6CED608F0168281B11ABEBEFACB5DE6B471C  : public JsonNode_t89D576EB46FFB3284319983B041AB01B7518C73D
{
	List_1_tFE70423E15F3F797BC0F99DCA699342A89DB00BA* ____properties;
	Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588* ____index;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D2899_t536BED7427F9782329E1E98815991437827FDD92 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D2899_t536BED7427F9782329E1E98815991437827FDD92__padding[2899];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D3985_tC29BEBBB25A24F5148607D8E88B92CDE4CEA266B 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D3985_tC29BEBBB25A24F5148607D8E88B92CDE4CEA266B__padding[3985];
	};
};
#pragma pack(pop, tp)
struct U3CPrivateImplementationDetailsU3E_t0628EC2558B8C9A382347E3EE1F74322D04C3AC7_StaticFields
{
	__StaticArrayInitTypeSizeU3D2899_t536BED7427F9782329E1E98815991437827FDD92 ___D98C6630CFFF6ADDA625584B321CA6B335D33C0822C50A8F3E31D9E061BBF2AF;
	__StaticArrayInitTypeSizeU3D3985_tC29BEBBB25A24F5148607D8E88B92CDE4CEA266B ___ECA7D0B9E8854C32AA119EB7096EE7DCBF4CA98653EC03B1638DAD09D8DE89B5;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif



IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 119346
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ProviderRequestMessage_get_RequestId_m3675BC85972B96C966FD896A3CB0A8E9EBD76B86 (ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:594>
		String_t* L_0 = __this->___U3CRequestIdU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 119347
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderRequestMessage_set_RequestId_m65EC6CB4BA882D7FBB48AE4ED084617362A34832 (ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:594>
		String_t* L_0 = ___0_value;
		__this->___U3CRequestIdU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CRequestIdU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 119348
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ProviderRequestMessage_get_Method_m2B4B0DC2D8C8B59C52B3EFECE2094C61DD51BDF9 (ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:597>
		String_t* L_0 = __this->___U3CMethodU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 119349
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderRequestMessage_set_Method_mB392F141E62F58288056534B7F083B1C8E5F5A2D (ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:597>
		String_t* L_0 = ___0_value;
		__this->___U3CMethodU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CMethodU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 119350
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JsonObject_t406D6CED608F0168281B11ABEBEFACB5DE6B471C* ProviderRequestMessage_get_Params_mABE4183490FFFD4EBBAABFDD7E25B23618C57136 (ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:600>
		JsonObject_t406D6CED608F0168281B11ABEBEFACB5DE6B471C* L_0 = __this->___U3CParamsU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 119351
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderRequestMessage_set_Params_mD964921F28DA77E98C0B91067BC884772A5A54DE (ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66* __this, JsonObject_t406D6CED608F0168281B11ABEBEFACB5DE6B471C* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:600>
		JsonObject_t406D6CED608F0168281B11ABEBEFACB5DE6B471C* L_0 = ___0_value;
		__this->___U3CParamsU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CParamsU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 119352
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderRequestMessage__ctor_mF914D2691BBFCAACDD7E093ECDE8865A3A0BA1C0 (ProviderRequestMessage_tB2B9B026D43C6E8D3F6B3C8A3073DE94938AEA66* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 119353
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ProviderResponseMessage_get_RequestId_m3B3B89674B3650CB38E2DEBE0C9BE7B5DC239303 (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:609>
		String_t* L_0 = __this->___U3CRequestIdU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 119354
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderResponseMessage_set_RequestId_m2174B1C8BE5C1B62172218197F3B9FE80E90D647 (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:609>
		String_t* L_0 = ___0_value;
		__this->___U3CRequestIdU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CRequestIdU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 119355
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ProviderResponseMessage_get_Success_m0CF90C2112E988A4BC1E31BB3C31F011AA8F216C (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:612>
		bool L_0 = __this->___U3CSuccessU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 119356
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderResponseMessage_set_Success_mDD0CF7F263F8CE8689405A75245281B79F115AD8 (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:612>
		bool L_0 = ___0_value;
		__this->___U3CSuccessU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 119357
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ProviderResponseMessage_get_Result_mFB1060E8BB592974219D7949F0A271C773BE10B4 (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:615>
		RuntimeObject* L_0 = __this->___U3CResultU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 119358
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderResponseMessage_set_Result_m285A461CC0772E4181581B57BE3E7B5F2556C838 (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:615>
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CResultU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CResultU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 119359
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ProviderResponseMessage_get_Error_m4196509402A2CA5B542B135F1851B31211DE1D85 (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:618>
		String_t* L_0 = __this->___U3CErrorU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 119360
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderResponseMessage_set_Error_m6EAB38174DC02F0A13F4C8E24564B66F1A19645B (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.core@c0efcbf2ba70/Scripts/MCPBridge/Runtime/ToolProviderClient.cs:618>
		String_t* L_0 = ___0_value;
		__this->___U3CErrorU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CErrorU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 119361
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProviderResponseMessage__ctor_mAB29EC713D45220CDEE0F7240646F0D6D18C0739 (ProviderResponseMessage_t456F9F71594CF812ABE4709620C9D34946907EF1* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
