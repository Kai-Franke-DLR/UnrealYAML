﻿#include "FYamlNode.h"

EYamlNodeType FYamlNode::Type() const {
	try {
		return Node.Type();
	} catch (YAML::InvalidNode) {
		UE_LOG(LogTemp, Warning, TEXT("Node was Invalid, returning default value for Type()!"))
		return EYamlNodeType::Undefined;
	}
}

bool FYamlNode::IsDefined() const {
	return Node.IsDefined();
}

bool FYamlNode::IsNull() const {
	return Node.IsNull();
}

bool FYamlNode::IsScalar() const {
	return Node.IsScalar();
}

bool FYamlNode::IsSequence() const {
	return Node.IsSequence();
}

bool FYamlNode::IsMap() const {
	return Node.IsMap();
}

FYamlNode::operator bool() const {
	return Node.IsDefined();
}

bool FYamlNode::operator!() const {
	return !Node.IsDefined();
}

EYamlEmitterStyle FYamlNode::Style() const {
	try {
		return Node.Style();
	} catch (YAML::InvalidNode) {
		UE_LOG(LogTemp, Warning, TEXT("Node was Invalid, returning default value for Style()!"))
		return YAML::EmitterStyle::Default;
	}
}

void FYamlNode::SetStyle(const EYamlEmitterStyle Style) {
	Node.SetStyle(Style);
}

bool FYamlNode::Is(const FYamlNode& Other) const {
	try {
		return Node.is(Other.Node);
	} catch (YAML::InvalidNode) {
		UE_LOG(LogTemp, Warning, TEXT("Node was Invalid, returning default value for Is() / Equals-Operation!"))
		return false;
	}
}

bool FYamlNode::operator==(const FYamlNode Other) const {
	return this->Is(Other);
}

bool FYamlNode::Reset(const FYamlNode& Other) {
	try {
		Node.reset(Other.Node);
		return true;
	} catch (YAML::InvalidNode) {
		UE_LOG(LogTemp, Warning, TEXT("Node was Invalid and will not be Reset!"))
		return false;
	}
}

FString FYamlNode::Scalar() const {
	try {
		return FString(Node.Scalar().c_str());
	} catch (YAML::InvalidNode) {
		UE_LOG(LogTemp, Warning, TEXT("Node was Invalid, returning default value for Scalar()"))
		return "";
	}
}

FString FYamlNode::GetContent() const {
	std::stringstream Stream;
	Stream << Node;
	return UTF8_TO_TCHAR(Stream.str().c_str());
}

int32 FYamlNode::Size() const {
	try {
		return Node.size();
	} catch (YAML::InvalidNode) {
		UE_LOG(LogTemp, Warning, TEXT("Node was Invalid, returning default value for Size()"))
		return 0;
	}
}

FYamlConstIterator FYamlNode::begin() const {
	return Node.begin();
}

FYamlIterator FYamlNode::begin() {
	return Node.begin();
}

FYamlConstIterator FYamlNode::end() const {
	return Node.end();
}

FYamlIterator FYamlNode::end() {
	return Node.end();
}
