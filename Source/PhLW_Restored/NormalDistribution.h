// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NormalDistribution.generated.h"

/**
 * 
 */
UCLASS()
class PHLW_RESTORED_API UNormalDistribution : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable)
		static float MarsagliaPolarMethod(const float mathExpct, const float stdDev);
	
};
