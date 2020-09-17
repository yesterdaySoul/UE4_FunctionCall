// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLib.h"

void UFunctionLib::ParseEvent(UObject* Sender, UObject* Caller, FString FunctionName, FString Params)
{
	FName const TargetFunctionName(*FunctionName);

	UFunction* Function = Caller->FindFunction(TargetFunctionName);
	if (!Function) return;

	uint8* Buffer = (uint8*)FMemory_Alloca(Function->ParmsSize);
	FMemory::Memzero(Buffer, Function->ParmsSize);

	for (TFieldIterator<UProperty> It(Function); It && It->HasAnyPropertyFlags(CPF_Parm); ++It)
	{
		UProperty* FunctionProperty = *It;
		FString Type = FunctionProperty->GetCPPType();

		if (Type == "FString")
		{
			*FunctionProperty->ContainerPtrToValuePtr<FString>(Buffer) = Params;
		}
		else if (Type == "UObject*")
		{
			*FunctionProperty->ContainerPtrToValuePtr<UObject*>(Buffer) = Sender;
		}
	}

	Caller->ProcessEvent(Function, Buffer);
}
