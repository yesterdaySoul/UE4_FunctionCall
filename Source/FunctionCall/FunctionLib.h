// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FunctionLib.generated.h"

/**
 * 
 */
UCLASS()
class FUNCTIONCALL_API UFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// call function by name (you can define the param rules in code later,eg:param count,param type and param order)
	UFUNCTION(BlueprintCallable,Category = "Funciton Caller")
		static void ParseEvent(UObject* Sender, UObject* Caller, FString FunctionName, FString Params);

};
