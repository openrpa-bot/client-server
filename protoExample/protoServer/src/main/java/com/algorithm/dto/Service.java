// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: service.proto

package com.algorithm.dto;

public final class Service {
  private Service() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_algorithm_Request_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_algorithm_Request_fieldAccessorTable;
  static final com.google.protobuf.Descriptors.Descriptor
    internal_static_algorithm_Response_descriptor;
  static final 
    com.google.protobuf.GeneratedMessageV3.FieldAccessorTable
      internal_static_algorithm_Response_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\rservice.proto\022\talgorithm\"\037\n\007Request\022\t\n" +
      "\001a\030\001 \001(\003\022\t\n\001b\030\002 \001(\003\"\032\n\010Response\022\016\n\006resul" +
      "t\030\001 \001(\003B\025\n\021com.algorithm.dtoP\001b\006proto3"
    };
    descriptor = com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        });
    internal_static_algorithm_Request_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_algorithm_Request_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_algorithm_Request_descriptor,
        new java.lang.String[] { "A", "B", });
    internal_static_algorithm_Response_descriptor =
      getDescriptor().getMessageTypes().get(1);
    internal_static_algorithm_Response_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessageV3.FieldAccessorTable(
        internal_static_algorithm_Response_descriptor,
        new java.lang.String[] { "Result", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}