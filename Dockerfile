FROM alpine:latest AS build

WORKDIR /app

RUN apk update && apk add --no-cache make gcc musl-dev

COPY src ./src

COPY include ./include

COPY makefile .

RUN mkdir -p bin obj

RUN make

RUN chmod +x /app/bin/bit-manipulation

FROM scratch

COPY --from=build /app/bin/bit-manipulation /bit-manipulation

EXPOSE 8080

ENTRYPOINT [ "./bit-manipulation" ]
