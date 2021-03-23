
# Generate the embedded source code.
mkdir -p ./nucleo-f446re/generated

cd EmbeddedProto
protoc --plugin=protoc-gen-eams=protoc-gen-eams -I../proto --eams_out=../nucleo-f446re/generated ../proto/nfc_messages.proto
cd -