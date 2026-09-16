#include "pch-cpp.hpp"





template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2>
struct InterfaceActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename T1, typename T2, typename T3>
struct InterfaceActionInvoker3
{
	typedef void (*Action)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};

struct Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83;
struct IEqualityComparer_1_tAE94C8F24AD5B94D4EE85CA9FC59E3409D41CAF7;
struct KeyCollection_t2EDD317F5771E575ACB63527B5AFB71291040342;
struct List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct ValueCollection_t238D0D2427C6B841A01F522A41540165A2C4AE76;
struct EntryU5BU5D_t1AF33AD0B7330843448956EC4277517081658AE7;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct ITelemetryWriterU5BU5D_t18E5B54E00AE923CDED28833DC8F3907E9025C25;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D;
struct ITraceProvider_tB1A9377AC62A6F0363E957530150015B5477232C;
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
struct RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8;
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t619E453BA46BDFB825A0003B7497271E40E8C0E6;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ITraceProvider_tB1A9377AC62A6F0363E957530150015B5477232C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339____86EF26C3BF2EECCD3A832FE302AC02245E7183567CC97593185D76625F10063A_FieldInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339____9A2BE8F183BEDA144A08B381CE9C882893FB59525EA43E51B8A5F319C5C08DE2_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral31D159E683556C06B3B3963D92483B6867EB3233;
IL2CPP_EXTERN_C String_t* _stringLiteralCE18B047107AA23D1AA9B2ED32D316148E02655F;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m216D0C31ED6C59F70921E4AA399B527E236367A6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mEA7391DC403FC7928F1B7A147AB66BC7ACE7488D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Profiler_ValidateArguments_m631DF788CA8A7DF599A5871AF4D7FA8B9C3B52CC_RuntimeMethod_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_t650418AC3EB6FBFFC34CCC45CA3202D5BB968ACD 
{
};
struct Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t1AF33AD0B7330843448956EC4277517081658AE7* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t2EDD317F5771E575ACB63527B5AFB71291040342* ____keys;
	ValueCollection_t238D0D2427C6B841A01F522A41540165A2C4AE76* ____values;
	RuntimeObject* ____syncRoot;
};
struct List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB  : public RuntimeObject
{
	ITelemetryWriterU5BU5D_t18E5B54E00AE923CDED28833DC8F3907E9025C25* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339  : public RuntimeObject
{
};
struct RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C  : public RuntimeObject
{
	List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* ____writers;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8  : public RuntimeObject
{
};
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t619E453BA46BDFB825A0003B7497271E40E8C0E6  : public RuntimeObject
{
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
struct VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367  : public RuntimeObject
{
};
struct Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 
{
	List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* ____list;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
struct Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A 
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ____list;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Guid_t 
{
	int32_t ____a;
	int16_t ____b;
	int16_t ____c;
	uint8_t ____d;
	uint8_t ____e;
	uint8_t ____f;
	uint8_t ____g;
	uint8_t ____h;
	uint8_t ____i;
	uint8_t ____j;
	uint8_t ____k;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 
{
	String_t* ___U3CValueU3Ek__BackingField;
};
struct OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_pinvoke
{
	char* ___U3CValueU3Ek__BackingField;
};
struct OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_com
{
	Il2CppChar* ___U3CValueU3Ek__BackingField;
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
struct __StaticArrayInitTypeSizeU3D362_t49E5D415720177227D6D45A5DE5EBFB88D5BFB70 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D362_t49E5D415720177227D6D45A5DE5EBFB88D5BFB70__padding[362];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D707_t572C25201B47F58E6B92D71E908FC9D9652EC7E7 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D707_t572C25201B47F58E6B92D71E908FC9D9652EC7E7__padding[707];
	};
};
#pragma pack(pop, tp)
struct MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___FilePathsData;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	bool ___IsEditorOnly;
};
struct MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_pinvoke
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_com
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 
{
	intptr_t ___value;
};
struct RuntimeTelemetryEventType_t4BEB1D7FC46E17F93551753C22A8270EDDAB5C0F 
{
	int32_t ___value__;
};
struct RuntimeTelemetryPoint_tBBD72A476DC73A63485838EB06A610DA5526C788 
{
	int32_t ___value__;
};
struct TerminationReason_t8122D6F10E49B7311FCE127D73C8033F54561EAD 
{
	int32_t ___value__;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB_StaticFields
{
	ITelemetryWriterU5BU5D_t18E5B54E00AE923CDED28833DC8F3907E9025C25* ___s_emptyArray;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339_StaticFields
{
	__StaticArrayInitTypeSizeU3D362_t49E5D415720177227D6D45A5DE5EBFB88D5BFB70 ___86EF26C3BF2EECCD3A832FE302AC02245E7183567CC97593185D76625F10063A;
	__StaticArrayInitTypeSizeU3D707_t572C25201B47F58E6B92D71E908FC9D9652EC7E7 ___9A2BE8F183BEDA144A08B381CE9C882893FB59525EA43E51B8A5F319C5C08DE2;
};
struct RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_StaticFields
{
	RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* ___U3CInstanceU3Ek__BackingField;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields
{
	RuntimeObject* ___traceProvider;
	bool ___profilingEnabled;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Guid_t_StaticFields
{
	Guid_t ___Empty;
};
struct OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_StaticFields
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___INVALID;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B (RuntimeArray* ___0_array, RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 ___1_fldHandle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Guid_t Guid_NewGuid_m1F4894E8DC089811D6252148AD5858E58D43A7BD (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Guid_ToString_m2BFFD5FA726E03FA707AAFCCF065896C46D5290C (Guid_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OperationID__ctor_mCCB860358B0F1F698D63F13170A1A153D85A1EED (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OperationID_get_IsAssigned_m2D22C0FD3AAA692663D4750CEE720B47EF851BF7 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* OperationID_ToString_mD2555FFE5F75C94E865A1D229A64E2DF0581C856 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OperationID_Equals_m76D155AFADF18D1A5FCB7082799398C8EA5EA586 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OperationID_GetHashCode_m2336700928EF6430F0ADC4FD881CB8880FF3A3F1 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) ;
inline void List_1__ctor_mEA7391DC403FC7928F1B7A147AB66BC7ACE7488D (List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
inline void List_1_Add_m216D0C31ED6C59F70921E4AA399B527E236367A6_inline (List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB*, RuntimeObject*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
inline Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F (List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 (*) (List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
inline void Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5 (Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950*, const RuntimeMethod*))Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared)(__this, method);
}
inline RuntimeObject* Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_inline (Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0 (Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 OperationID_op_Explicit_mC930842D2E43B4CDA982CA11C15B570D73EA79F1 (String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_LogPoint_mB2405F5031BD120BD3BFF8BE3E4D54B73CA34316 (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___0_operationId, int32_t ___1_point, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry__ctor_m098F268AC921BC7DF2BC368C94B77EB98154C48F (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Profiler_BeginSample_m640E26B682D803CC5DB4EDFDF2F6E83771BF0BE4_inline (String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Profiler_EndSample_m3FCA26738A87C0B8E352533AD48E2A16B047A757 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityProfilerTraceProvider__ctor_m358582FCDAB385B56E9B8917B97A9D824F98D527 (UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Profiler_ValidateArguments_m631DF788CA8A7DF599A5871AF4D7FA8B9C3B52CC_inline (String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Profiler_BeginSampleImpl_m7CA0C092A61229CA7BF617E521F2DE0E2B155CEA (String_t* ___0_name, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_targetObject, const RuntimeMethod* method) ;
inline void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478 (String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, String_t* ___1_paramName, const RuntimeMethod* method) ;
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
// Method Definition Index: 133436
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199 UnitySourceGeneratedAssemblyMonoScriptTypes_v1_Get_mC0B8EB0D519F5AAE3428757C2F865890F4E27A20 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339____86EF26C3BF2EECCD3A832FE302AC02245E7183567CC97593185D76625F10063A_FieldInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339____9A2BE8F183BEDA144A08B381CE9C882893FB59525EA43E51B8A5F319C5C08DE2_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199 V_0;
	memset((&V_0), 0, sizeof(V_0));
	MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)707));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_2 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339____9A2BE8F183BEDA144A08B381CE9C882893FB59525EA43E51B8A5F319C5C08DE2_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_1, L_2, NULL);
		(&V_0)->___FilePathsData = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___FilePathsData), (void*)L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)362));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = L_3;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_5 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_tA0954D2F19BC576CBF5A6C6A5DD4F6C081B3C339____86EF26C3BF2EECCD3A832FE302AC02245E7183567CC97593185D76625F10063A_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_4, L_5, NULL);
		(&V_0)->___TypesData = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___TypesData), (void*)L_4);
		(&V_0)->___TotalFiles = 6;
		(&V_0)->___TotalTypes = 6;
		(&V_0)->___IsEditorOnly = (bool)0;
		MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199 L_6 = V_0;
		V_1 = L_6;
		goto IL_005d;
	}

IL_005d:
	{
		MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199 L_7 = V_1;
		return L_7;
	}
}
// Method Definition Index: 133437
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnitySourceGeneratedAssemblyMonoScriptTypes_v1__ctor_m44E2E3746E0210639DBEEBB6F222D54526796DB3 (UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t619E453BA46BDFB825A0003B7497271E40E8C0E6* __this, const RuntimeMethod* method) 
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
IL2CPP_EXTERN_C void MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshal_pinvoke(const MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199& unmarshaled, MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_pinvoke& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshal_pinvoke_back(const MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_pinvoke& marshaled, MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshal_pinvoke_cleanup(MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
IL2CPP_EXTERN_C void MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshal_com(const MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199& unmarshaled, MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_com& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshal_com_back(const MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_com& marshaled, MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshal_com_cleanup(MonoScriptData_t19304DB78219AC2AE13856EB57E8AB386EB0D199_marshaled_com& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshal_pinvoke(const OperationID_t4293F09A213A61A8354B3641BC077A571A514F17& unmarshaled, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_pinvoke& marshaled)
{
	marshaled.___U3CValueU3Ek__BackingField = il2cpp_codegen_marshal_string(unmarshaled.___U3CValueU3Ek__BackingField);
}
IL2CPP_EXTERN_C void OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshal_pinvoke_back(const OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_pinvoke& marshaled, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17& unmarshaled)
{
	unmarshaled.___U3CValueU3Ek__BackingField = il2cpp_codegen_marshal_string_result(marshaled.___U3CValueU3Ek__BackingField);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___U3CValueU3Ek__BackingField), (void*)il2cpp_codegen_marshal_string_result(marshaled.___U3CValueU3Ek__BackingField));
}
IL2CPP_EXTERN_C void OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshal_pinvoke_cleanup(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_marshal_free(marshaled.___U3CValueU3Ek__BackingField);
	marshaled.___U3CValueU3Ek__BackingField = NULL;
}
IL2CPP_EXTERN_C void OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshal_com(const OperationID_t4293F09A213A61A8354B3641BC077A571A514F17& unmarshaled, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_com& marshaled)
{
	marshaled.___U3CValueU3Ek__BackingField = il2cpp_codegen_marshal_bstring(unmarshaled.___U3CValueU3Ek__BackingField);
}
IL2CPP_EXTERN_C void OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshal_com_back(const OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_com& marshaled, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17& unmarshaled)
{
	unmarshaled.___U3CValueU3Ek__BackingField = il2cpp_codegen_marshal_bstring_result(marshaled.___U3CValueU3Ek__BackingField);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___U3CValueU3Ek__BackingField), (void*)il2cpp_codegen_marshal_bstring_result(marshaled.___U3CValueU3Ek__BackingField));
}
IL2CPP_EXTERN_C void OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshal_com_cleanup(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_marshaled_com& marshaled)
{
	il2cpp_codegen_marshal_free_bstring(marshaled.___U3CValueU3Ek__BackingField);
	marshaled.___U3CValueU3Ek__BackingField = NULL;
}
// Method Definition Index: 133443
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:32>
		String_t* L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C  String_t* OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<OperationID_t4293F09A213A61A8354B3641BC077A571A514F17*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133444
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OperationID__ctor_mCCB860358B0F1F698D63F13170A1A153D85A1EED (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	bool V_0 = false;
	Guid_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:36>
		String_t* L_0 = ___0_value;
		V_0 = (bool)((((RuntimeObject*)(String_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0020;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:38>
		Guid_t L_2;
		L_2 = Guid_NewGuid_m1F4894E8DC089811D6252148AD5858E58D43A7BD(NULL);
		V_1 = L_2;
		String_t* L_3;
		L_3 = Guid_ToString_m2BFFD5FA726E03FA707AAFCCF065896C46D5290C((&V_1), NULL);
		___0_value = L_3;
	}

IL_0020:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:41>
		String_t* L_4 = ___0_value;
		__this->___U3CValueU3Ek__BackingField = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CValueU3Ek__BackingField), (void*)L_4);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:42>
		return;
	}
}
IL2CPP_EXTERN_C  void OperationID__ctor_mCCB860358B0F1F698D63F13170A1A153D85A1EED_AdjustorThunk (RuntimeObject* __this, String_t* ___0_value, const RuntimeMethod* method)
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<OperationID_t4293F09A213A61A8354B3641BC077A571A514F17*>(__this + _offset);
	OperationID__ctor_mCCB860358B0F1F698D63F13170A1A153D85A1EED(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 133445
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 OperationID_Create_m32E738D1ED808CBDD1293228B0EE7738E8DE193B (String_t* ___0_value, const RuntimeMethod* method) 
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:46>
		String_t* L_0 = ___0_value;
		OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_1;
		memset((&L_1), 0, sizeof(L_1));
		OperationID__ctor_mCCB860358B0F1F698D63F13170A1A153D85A1EED((&L_1), L_0, NULL);
		V_0 = L_1;
		goto IL_000a;
	}

IL_000a:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:47>
		OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 133446
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OperationID_get_IsAssigned_m2D22C0FD3AAA692663D4750CEE720B47EF851BF7 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:52>
		il2cpp_codegen_runtime_class_init_inline(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		String_t* L_0;
		L_0 = OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline(__this, NULL);
		return (bool)((!(((RuntimeObject*)(String_t*)L_0) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool OperationID_get_IsAssigned_m2D22C0FD3AAA692663D4750CEE720B47EF851BF7_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<OperationID_t4293F09A213A61A8354B3641BC077A571A514F17*>(__this + _offset);
	bool _returnValue;
	_returnValue = OperationID_get_IsAssigned_m2D22C0FD3AAA692663D4750CEE720B47EF851BF7(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133447
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* OperationID_ToString_mD2555FFE5F75C94E865A1D229A64E2DF0581C856 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:54>
		il2cpp_codegen_runtime_class_init_inline(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		String_t* L_0;
		L_0 = OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline(__this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C  String_t* OperationID_ToString_mD2555FFE5F75C94E865A1D229A64E2DF0581C856_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<OperationID_t4293F09A213A61A8354B3641BC077A571A514F17*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = OperationID_ToString_mD2555FFE5F75C94E865A1D229A64E2DF0581C856(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133448
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* OperationID_op_Implicit_mECD2A625F5896A5CBEFD4B359112C765C85428BF (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___0_correlationId, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:56>
		il2cpp_codegen_runtime_class_init_inline(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		String_t* L_0;
		L_0 = OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline((&___0_correlationId), NULL);
		return L_0;
	}
}
// Method Definition Index: 133449
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 OperationID_op_Explicit_mC930842D2E43B4CDA982CA11C15B570D73EA79F1 (String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:57>
		String_t* L_0 = ___0_value;
		OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_1;
		memset((&L_1), 0, sizeof(L_1));
		OperationID__ctor_mCCB860358B0F1F698D63F13170A1A153D85A1EED((&L_1), L_0, NULL);
		return L_1;
	}
}
// Method Definition Index: 133450
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 OperationID_op_Implicit_mADE3028CCD5B93C3486481245E53217D546A38EC (Guid_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:58>
		String_t* L_0;
		L_0 = Guid_ToString_m2BFFD5FA726E03FA707AAFCCF065896C46D5290C((&___0_value), NULL);
		OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_1;
		memset((&L_1), 0, sizeof(L_1));
		OperationID__ctor_mCCB860358B0F1F698D63F13170A1A153D85A1EED((&L_1), L_0, NULL);
		return L_1;
	}
}
// Method Definition Index: 133451
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OperationID_Equals_m76D155AFADF18D1A5FCB7082799398C8EA5EA586 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t G_B3_0 = 0;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:60>
		RuntimeObject* L_0 = ___0_obj;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var)))
		{
			goto IL_0023;
		}
	}
	{
		RuntimeObject* L_1 = ___0_obj;
		V_0 = ((*(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17*)UnBox(L_1, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var)));
		il2cpp_codegen_runtime_class_init_inline(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		String_t* L_2;
		L_2 = OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline(__this, NULL);
		String_t* L_3;
		L_3 = OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline((&V_0), NULL);
		bool L_4;
		L_4 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_2, L_3, NULL);
		G_B3_0 = ((int32_t)(L_4));
		goto IL_0024;
	}

IL_0023:
	{
		G_B3_0 = 0;
	}

IL_0024:
	{
		return (bool)G_B3_0;
	}
}
IL2CPP_EXTERN_C  bool OperationID_Equals_m76D155AFADF18D1A5FCB7082799398C8EA5EA586_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<OperationID_t4293F09A213A61A8354B3641BC077A571A514F17*>(__this + _offset);
	bool _returnValue;
	_returnValue = OperationID_Equals_m76D155AFADF18D1A5FCB7082799398C8EA5EA586(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// Method Definition Index: 133452
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OperationID_GetHashCode_m2336700928EF6430F0ADC4FD881CB8880FF3A3F1 (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	int32_t V_1 = 0;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:63>
		il2cpp_codegen_runtime_class_init_inline(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = OperationID_get_IsAssigned_m2D22C0FD3AAA692663D4750CEE720B47EF851BF7(__this, NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_001a;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:65>
		il2cpp_codegen_runtime_class_init_inline(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		String_t* L_2;
		L_2 = OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline(__this, NULL);
		NullCheck(L_2);
		int32_t L_3;
		L_3 = VirtualFuncInvoker0< int32_t >::Invoke(2, L_2);
		V_1 = L_3;
		goto IL_001e;
	}

IL_001a:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:68>
		V_1 = 0;
		goto IL_001e;
	}

IL_001e:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:69>
		int32_t L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C  int32_t OperationID_GetHashCode_m2336700928EF6430F0ADC4FD881CB8880FF3A3F1_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<OperationID_t4293F09A213A61A8354B3641BC077A571A514F17*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = OperationID_GetHashCode_m2336700928EF6430F0ADC4FD881CB8880FF3A3F1(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 133453
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OperationID__cctor_m22BB4079CE78925B18A372960D77207FCD585F0F (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:30>
		il2cpp_codegen_initobj((&((OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_StaticFields*)il2cpp_codegen_static_fields_for(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var))->___INVALID), sizeof(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17));
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
// Method Definition Index: 133454
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry__ctor_m098F268AC921BC7DF2BC368C94B77EB98154C48F (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mEA7391DC403FC7928F1B7A147AB66BC7ACE7488D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:31>
		List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* L_0 = (List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB*)il2cpp_codegen_object_new(List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB_il2cpp_TypeInfo_var);
		List_1__ctor_mEA7391DC403FC7928F1B7A147AB66BC7ACE7488D(L_0, List_1__ctor_mEA7391DC403FC7928F1B7A147AB66BC7ACE7488D_RuntimeMethod_var);
		__this->____writers = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____writers), (void*)L_0);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:33>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:34>
		return;
	}
}
// Method Definition Index: 133455
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* RuntimeTelemetry_get_Instance_m85EB5D1188C03073D2BE99BED36CFB2416489614 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:36>
		il2cpp_codegen_runtime_class_init_inline(RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var);
		RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* L_0 = ((RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_StaticFields*)il2cpp_codegen_static_fields_for(RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var))->___U3CInstanceU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 133456
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_RegisterWriter_m408025C6CC8AEA45A7DDAB93D0CEA2F0ED002E3B (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, RuntimeObject* ___0_writer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m216D0C31ED6C59F70921E4AA399B527E236367A6_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:40>
		List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* L_0 = __this->____writers;
		RuntimeObject* L_1 = ___0_writer;
		NullCheck(L_0);
		List_1_Add_m216D0C31ED6C59F70921E4AA399B527E236367A6_inline(L_0, L_1, List_1_Add_m216D0C31ED6C59F70921E4AA399B527E236367A6_RuntimeMethod_var);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:41>
		return;
	}
}
// Method Definition Index: 133457
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_StartEvent_m4D4584E78CD1BEE5BA8DB7D887C4715965765C4E (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___0_operationId, int32_t ___1_runtimeTelemetryEventType, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 V_0;
	memset((&V_0), 0, sizeof(V_0));
	RuntimeObject* V_1 = NULL;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:45>
		List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* L_0 = __this->____writers;
		NullCheck(L_0);
		Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 L_1;
		L_1 = List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F(L_0, List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002e:
			{
				Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5((&V_0), Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0023_1;
			}

IL_0010_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:45>
				RuntimeObject* L_2;
				L_2 = Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_inline((&V_0), Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
				V_1 = L_2;
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:47>
				RuntimeObject* L_3 = V_1;
				OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_4 = ___0_operationId;
				int32_t L_5 = ___1_runtimeTelemetryEventType;
				NullCheck(L_3);
				InterfaceActionInvoker2< OperationID_t4293F09A213A61A8354B3641BC077A571A514F17, int32_t >::Invoke(0, ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var, L_3, L_4, L_5);
			}

IL_0023_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:45>
				bool L_6;
				L_6 = Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0((&V_0), Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
				if (L_6)
				{
					goto IL_0010_1;
				}
			}
			{
				goto IL_003d;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003d:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:49>
		return;
	}
}
// Method Definition Index: 133458
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_LogEventTermination_m8CA3C902E33D8604D0AC4B826B15F9F2F0AD2990 (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___0_operationId, int32_t ___1_reason, String_t* ___2_message, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 V_0;
	memset((&V_0), 0, sizeof(V_0));
	RuntimeObject* V_1 = NULL;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:54>
		List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* L_0 = __this->____writers;
		NullCheck(L_0);
		Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 L_1;
		L_1 = List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F(L_0, List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002f:
			{
				Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5((&V_0), Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0024_1;
			}

IL_0010_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:54>
				RuntimeObject* L_2;
				L_2 = Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_inline((&V_0), Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
				V_1 = L_2;
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:56>
				RuntimeObject* L_3 = V_1;
				OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_4 = ___0_operationId;
				int32_t L_5 = ___1_reason;
				String_t* L_6 = ___2_message;
				NullCheck(L_3);
				InterfaceActionInvoker3< OperationID_t4293F09A213A61A8354B3641BC077A571A514F17, int32_t, String_t* >::Invoke(1, ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var, L_3, L_4, L_5, L_6);
			}

IL_0024_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:54>
				bool L_7;
				L_7 = Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0((&V_0), Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
				if (L_7)
				{
					goto IL_0010_1;
				}
			}
			{
				goto IL_003e;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003e:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:58>
		return;
	}
}
// Method Definition Index: 133459
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_LogInstantaneousEvent_m8A3F8D4C457F53DC9D99D69AEB2182E279E24443 (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___0_operationId, int32_t ___1_runtimeTelemetryEventType, Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* ___2_annotations, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 V_0;
	memset((&V_0), 0, sizeof(V_0));
	RuntimeObject* V_1 = NULL;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:62>
		List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* L_0 = __this->____writers;
		NullCheck(L_0);
		Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 L_1;
		L_1 = List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F(L_0, List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002f:
			{
				Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5((&V_0), Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0024_1;
			}

IL_0010_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:62>
				RuntimeObject* L_2;
				L_2 = Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_inline((&V_0), Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
				V_1 = L_2;
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:64>
				RuntimeObject* L_3 = V_1;
				OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_4 = ___0_operationId;
				int32_t L_5 = ___1_runtimeTelemetryEventType;
				Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* L_6 = ___2_annotations;
				NullCheck(L_3);
				InterfaceActionInvoker3< OperationID_t4293F09A213A61A8354B3641BC077A571A514F17, int32_t, Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* >::Invoke(2, ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var, L_3, L_4, L_5, L_6);
			}

IL_0024_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:62>
				bool L_7;
				L_7 = Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0((&V_0), Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
				if (L_7)
				{
					goto IL_0010_1;
				}
			}
			{
				goto IL_003e;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003e:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:66>
		return;
	}
}
// Method Definition Index: 133460
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_LogPoint_mB2405F5031BD120BD3BFF8BE3E4D54B73CA34316 (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___0_operationId, int32_t ___1_point, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 V_0;
	memset((&V_0), 0, sizeof(V_0));
	RuntimeObject* V_1 = NULL;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:70>
		List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* L_0 = __this->____writers;
		NullCheck(L_0);
		Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 L_1;
		L_1 = List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F(L_0, List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002e:
			{
				Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5((&V_0), Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0023_1;
			}

IL_0010_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:70>
				RuntimeObject* L_2;
				L_2 = Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_inline((&V_0), Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
				V_1 = L_2;
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:72>
				RuntimeObject* L_3 = V_1;
				OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_4 = ___0_operationId;
				int32_t L_5 = ___1_point;
				NullCheck(L_3);
				InterfaceActionInvoker2< OperationID_t4293F09A213A61A8354B3641BC077A571A514F17, int32_t >::Invoke(3, ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var, L_3, L_4, L_5);
			}

IL_0023_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:70>
				bool L_6;
				L_6 = Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0((&V_0), Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
				if (L_6)
				{
					goto IL_0010_1;
				}
			}
			{
				goto IL_003d;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003d:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:74>
		return;
	}
}
// Method Definition Index: 133461
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_LogPoint_m05A4CBB58BDA15FA4F3FA69FEA9922C3BE990900 (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, String_t* ___0_operationId, int32_t ___1_point, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:78>
		String_t* L_0 = ___0_operationId;
		il2cpp_codegen_runtime_class_init_inline(OperationID_t4293F09A213A61A8354B3641BC077A571A514F17_il2cpp_TypeInfo_var);
		OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_1;
		L_1 = OperationID_op_Explicit_mC930842D2E43B4CDA982CA11C15B570D73EA79F1(L_0, NULL);
		int32_t L_2 = ___1_point;
		RuntimeTelemetry_LogPoint_mB2405F5031BD120BD3BFF8BE3E4D54B73CA34316(__this, L_1, L_2, NULL);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:79>
		return;
	}
}
// Method Definition Index: 133462
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry_AnnotateEvent_m504EE11A8AA7EC079282C9959C60560F580F7F24 (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* __this, OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 ___0_operationID, String_t* ___1_annotationKey, String_t* ___2_annotationValue, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 V_0;
	memset((&V_0), 0, sizeof(V_0));
	RuntimeObject* V_1 = NULL;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:83>
		List_1_tD2F0B218EBE3AAB2098ED44FE9FA996EB9D554FB* L_0 = __this->____writers;
		NullCheck(L_0);
		Enumerator_t23FF65E29BEAF18B2F59B7D29E33A05C6EC0B950 L_1;
		L_1 = List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F(L_0, List_1_GetEnumerator_m5225DADF2082A11DCBC572B658A3A2867963069F_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002f:
			{
				Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5((&V_0), Enumerator_Dispose_m15D3145C2A9A78CCE59D9264F3208804D38824E5_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0024_1;
			}

IL_0010_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:83>
				RuntimeObject* L_2;
				L_2 = Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_inline((&V_0), Enumerator_get_Current_mCE409ABE761E58D48336B336C21B033146FA65F0_RuntimeMethod_var);
				V_1 = L_2;
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:85>
				RuntimeObject* L_3 = V_1;
				OperationID_t4293F09A213A61A8354B3641BC077A571A514F17 L_4 = ___0_operationID;
				String_t* L_5 = ___1_annotationKey;
				String_t* L_6 = ___2_annotationValue;
				NullCheck(L_3);
				InterfaceActionInvoker3< OperationID_t4293F09A213A61A8354B3641BC077A571A514F17, String_t*, String_t* >::Invoke(4, ITelemetryWriter_t39CDA86E3AB72B7CD1B48B4EEB13F11B25DB298D_il2cpp_TypeInfo_var, L_3, L_4, L_5, L_6);
			}

IL_0024_1:
			{
				//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:83>
				bool L_7;
				L_7 = Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0((&V_0), Enumerator_MoveNext_m911AEB8AFFAB38517D50C4BF383B11BF60FABEC0_RuntimeMethod_var);
				if (L_7)
				{
					goto IL_0010_1;
				}
			}
			{
				goto IL_003e;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003e:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:87>
		return;
	}
}
// Method Definition Index: 133463
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeTelemetry__cctor_m0B3E4AD4AD979D9C57545CB007C17A9C7BCB88CC (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/RuntimeTelemetry.cs:36>
		RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C* L_0 = (RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C*)il2cpp_codegen_object_new(RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var);
		RuntimeTelemetry__ctor_m098F268AC921BC7DF2BC368C94B77EB98154C48F(L_0, NULL);
		((RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_StaticFields*)il2cpp_codegen_static_fields_for(RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var))->___U3CInstanceU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_StaticFields*)il2cpp_codegen_static_fields_for(RuntimeTelemetry_t91BC53846E4410B32288E2A95DE8ACD121FAA83C_il2cpp_TypeInfo_var))->___U3CInstanceU3Ek__BackingField), (void*)L_0);
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
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 133466
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityProfilerTraceProvider_BeginSample_mA8392D382BC54B9C425200DCAF3C9E66E117817F (UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8* __this, String_t* ___0_sampleName, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/UnityProfilerTraceProvider.cs:33>
		String_t* L_0 = ___0_sampleName;
		Profiler_BeginSample_m640E26B682D803CC5DB4EDFDF2F6E83771BF0BE4_inline(L_0, NULL);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/UnityProfilerTraceProvider.cs:34>
		return;
	}
}
// Method Definition Index: 133467
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityProfilerTraceProvider_EndSample_mE045FF8E1A3B4E7A8FB4D96274A2DBC42BA689F4 (UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8* __this, String_t* ___0_sampleName, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/UnityProfilerTraceProvider.cs:39>
		Profiler_EndSample_m3FCA26738A87C0B8E352533AD48E2A16B047A757(NULL);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/UnityProfilerTraceProvider.cs:40>
		return;
	}
}
// Method Definition Index: 133468
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityProfilerTraceProvider__ctor_m358582FCDAB385B56E9B8917B97A9D824F98D527 (UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 133469
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VsdkProfiler_BeginSample_m7A587499EB41C75ED88104CD52F45BD1DDFE7D1E (String_t* ___0_sampleName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITraceProvider_tB1A9377AC62A6F0363E957530150015B5477232C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:50>
		il2cpp_codegen_runtime_class_init_inline(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var);
		bool L_0 = ((VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields*)il2cpp_codegen_static_fields_for(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var))->___profilingEnabled;
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:52>
		il2cpp_codegen_runtime_class_init_inline(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var);
		RuntimeObject* L_2 = ((VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields*)il2cpp_codegen_static_fields_for(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var))->___traceProvider;
		String_t* L_3 = ___0_sampleName;
		NullCheck(L_2);
		InterfaceActionInvoker1< String_t* >::Invoke(0, ITraceProvider_tB1A9377AC62A6F0363E957530150015B5477232C_il2cpp_TypeInfo_var, L_2, L_3);
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:54>
		return;
	}
}
// Method Definition Index: 133470
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VsdkProfiler_EndSample_mF54C86B652790F64541C402DC6614B9D7DBAD087 (String_t* ___0_sampleName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITraceProvider_tB1A9377AC62A6F0363E957530150015B5477232C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:62>
		il2cpp_codegen_runtime_class_init_inline(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var);
		bool L_0 = ((VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields*)il2cpp_codegen_static_fields_for(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var))->___profilingEnabled;
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:64>
		il2cpp_codegen_runtime_class_init_inline(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var);
		RuntimeObject* L_2 = ((VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields*)il2cpp_codegen_static_fields_for(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var))->___traceProvider;
		String_t* L_3 = ___0_sampleName;
		NullCheck(L_2);
		InterfaceActionInvoker1< String_t* >::Invoke(1, ITraceProvider_tB1A9377AC62A6F0363E957530150015B5477232C_il2cpp_TypeInfo_var, L_2, L_3);
	}

IL_0018:
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:66>
		return;
	}
}
// Method Definition Index: 133471
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VsdkProfiler__cctor_m6E89E420EE1E3A725AAE9EAAD711C3CE6D924B47 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:32>
		UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8* L_0 = (UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8*)il2cpp_codegen_object_new(UnityProfilerTraceProvider_t86B23207CC5DAA4522C952C52B9C7714E33F8BD8_il2cpp_TypeInfo_var);
		UnityProfilerTraceProvider__ctor_m358582FCDAB385B56E9B8917B97A9D824F98D527(L_0, NULL);
		((VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields*)il2cpp_codegen_static_fields_for(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var))->___traceProvider = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields*)il2cpp_codegen_static_fields_for(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var))->___traceProvider), (void*)L_0);
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/Tracing/VsdkProfiler.cs:39>
		((VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_StaticFields*)il2cpp_codegen_static_fields_for(VsdkProfiler_tE4303169D1ACEE0855B0206EA1D780469F7FC367_il2cpp_TypeInfo_var))->___profilingEnabled = (bool)1;
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
// Method Definition Index: 133443
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* OperationID_get_Value_mF6E0A8C6082A179B51AB2211B89A056C4E99A079_inline (OperationID_t4293F09A213A61A8354B3641BC077A571A514F17* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:./Library/PackageCache/com.meta.xr.sdk.voice@856439ff2689/Lib/Telemetry/Scripts/Runtime/OperationID.cs:32>
		String_t* L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 76646
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Profiler_BeginSample_m640E26B682D803CC5DB4EDFDF2F6E83771BF0BE4_inline (String_t* ___0_name, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = ___0_name;
		Profiler_ValidateArguments_m631DF788CA8A7DF599A5871AF4D7FA8B9C3B52CC_inline(L_0, NULL);
		String_t* L_1 = ___0_name;
		Profiler_BeginSampleImpl_m7CA0C092A61229CA7BF617E521F2DE0E2B155CEA(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		return;
	}
}
// Method Definition Index: 11889
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		return;
	}
}
// Method Definition Index: 11941
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
// Method Definition Index: 76647
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Profiler_ValidateArguments_m631DF788CA8A7DF599A5871AF4D7FA8B9C3B52CC_inline (String_t* ___0_name, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		String_t* L_0 = ___0_name;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		V_0 = L_1;
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_001c;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_3 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral31D159E683556C06B3B3963D92483B6867EB3233)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralCE18B047107AA23D1AA9B2ED32D316148E02655F)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Profiler_ValidateArguments_m631DF788CA8A7DF599A5871AF4D7FA8B9C3B52CC_RuntimeMethod_var)));
	}

IL_001c:
	{
		return;
	}
}
